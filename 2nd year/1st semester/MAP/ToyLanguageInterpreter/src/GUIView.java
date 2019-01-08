import Controller.InterpreterController;
import Model.Expression.ArithExp;
import Model.Expression.ConstExp;
import Model.Expression.ReadHeapExp;
import Model.Expression.VarExp;
import Model.ProgramState;
import Model.Statement.*;
import Model.Statement.HeapStatements.NewStmt;
import Model.Statement.HeapStatements.WriteHeapStmt;
import Model.Utils.MyHeap;
import Model.Utils.Tuple;
import Repository.IRepo;
import Repository.Repo;
import javafx.application.Application;
import javafx.beans.property.ReadOnlyIntegerWrapper;
import javafx.beans.property.ReadOnlyMapProperty;
import javafx.beans.property.ReadOnlyObjectWrapper;
import javafx.beans.property.ReadOnlyStringWrapper;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.text.Text;
import javafx.stage.Stage;

import java.io.BufferedReader;
import java.util.HashMap;
import java.util.Map;

public class GUIView extends Application {
    private InterpreterController ctrl1, ctrl2, ctrl3, ctrl4, ctrl5, ctrl6, ctrl7, ctrl8;
    private InterpreterController currentController;

    // we can't modify variables in lambdas without them being final
    // this is a workaround
    private int currIndex[] = {0};

    private Text noOfPrgStatesText;

    private TableView heapTableView;
    private ListView<Text> outListView;
    private TableView fileTableView;
    private ListView<Text> programStatesListView;
    private TableView symTableView;
    private ListView<Text> exeStackListView;

    Button oneStepBtn;

    public static void main(String[] args) {
        launch(args);
    }

    private InterpreterController getControllerForSelectedListViewIndex() {
        switch (this.currIndex[0]) {
            case 0:
                return ctrl1;

            case 1:
                return ctrl2;

            case 2:
                return ctrl3;

            case 3:
                return ctrl4;

            case 4:
                return ctrl5;

            case 5:
                return ctrl6;

            case 6:
                return ctrl7;

            case 7:
                return ctrl8;

            default:
                return ctrl1;
        }
    }

    private void updateHeapTableView() {
        //////////// Update heapTableView
        // TODO put this in a function so we don't copy useless code over and over again
        this.heapTableView.getItems().clear();
        this.currentController.getRepo().getProgramStates().forEach(
                (ps) -> {
                    ObservableList<Map.Entry<Integer, Integer>> heapTableViewItems = FXCollections.observableArrayList(ps.getHeap().getMap().entrySet());
                    this.heapTableView.getItems().addAll(heapTableViewItems);
                    //System.out.println("ASD");
                    //for (Map.Entry<Integer, Integer> heapEntry : ps.getHeap().getMap().entrySet()) {

                    //}
                }
        );
    }

    private void updateOutListView() {
        this.outListView.getItems().clear();
        this.currentController.getRepo().getProgramStates().forEach(
                (ps) -> {
                    Text psOutputText = new Text(ps.getOutput().toString());
                    psOutputText.wrappingWidthProperty().bind(outListView.widthProperty());
                    this.outListView.getItems().add(psOutputText);
                }
        );
    }

    private void updateFileTableView() {
        this.fileTableView.getItems().clear();
        //this.currentController.executeAllSteps();
        this.currentController.getRepo().getProgramStates().forEach(
                (ps) -> {
                    ObservableList<Map.Entry<Integer, Tuple<String, BufferedReader>>> fileTableViewItems = FXCollections.observableArrayList(ps.getFileTable().getMap().entrySet());
                    this.fileTableView.getItems().addAll(fileTableViewItems);
                }
        );
    }

    private void updateProgramStatesListView() {
        this.programStatesListView.getItems().clear();
        this.currentController.getRepo().getProgramStates().forEach(
                (ps) -> {
                    ps.getExeStack().getStack().forEach(
                            (ex) -> {
                                Text psText = new Text(ex.toString());
                                psText.wrappingWidthProperty().bind(this.programStatesListView.widthProperty());
                                this.programStatesListView.getItems().add(psText);
                            }
                    );
                }
        );
    }

    public void updateSymTableView() {
        this.symTableView.getItems().clear();
        this.currentController.getRepo().getProgramStates().forEach(
                (ps) -> {
                    ObservableList<Map.Entry<String, Integer>> symTableViewItems = FXCollections.observableArrayList(ps.getSymTable().getMap().entrySet());
                    this.symTableView.getItems().addAll(symTableViewItems);
                }
        );
    }

    public void updateExeStackListView() {
        this.exeStackListView.getItems().clear();
        this.currentController.getRepo().getProgramStates().forEach(
                (ps) -> {
                    ObservableList<Text> exeStackListViewItems = FXCollections.observableArrayList();
                    for (IStatement elem : ps.getExeStack().getStack()) {
                        Text t = new Text(elem.toString());
                        t.wrappingWidthProperty().bind(this.exeStackListView.widthProperty());
                        exeStackListViewItems.add(t);
                    }

                    this.exeStackListView.getItems().addAll(exeStackListViewItems);
                }
        );
    }

    @Override
    public void start(Stage primaryStage) throws InterruptedException {
        /////////////////////////////////
        // Backend
        /////////////////////////////////
        // C:\Users\necso\Desktop\926\src\openrfiletest.txt

        // v = 2; print(v); makeZero(v); print(v)
        //IStatement ex1 = new CompoundStm(new AssignmentStm("v",new ConstExp(2)), new PrintStm(new
        //        VarExp("v")));
        IStatement ex1 = new CompoundStm(new AssignmentStm("v", new ConstExp(2)),
                new CompoundStm(new PrintStm(new VarExp("v")), new CompoundStm(new MakeZeroStmt("v"), new PrintStm(new VarExp("v")))));

        // a = 2 + 3 * 5; b = a + 1; print(b)
        IStatement ex2 =  new CompoundStm(new AssignmentStm("a", new ArithExp(new ConstExp(2),'+',new
                ArithExp(new ConstExp(3),'*' ,new ConstExp(5)))),
                new CompoundStm(new AssignmentStm("b",new ArithExp(new VarExp("a"),'+', new
                        ConstExp(1))), new PrintStm(new VarExp("b"))));

        // a = 2 - 2; (if a then v = 2 else v = 3); print(v)
        IStatement ex3 = new CompoundStm(new AssignmentStm("a", new ArithExp( new ConstExp(2),'-', new
                ConstExp(1))), new CompoundStm(new IfStm(new VarExp("a"), new AssignmentStm("v", new ConstExp(2)), new
                AssignmentStm("v", new ConstExp(3))), new PrintStm(new VarExp("v"))));

        //

        IStatement ex4 = new CompoundStm(new OpenRFileStmt("var_f", "openrfiletest.txt"),
                new CompoundStm(new ReadFileStmt(new VarExp("var_f"), "var_c"),
                        new CompoundStm(new PrintStm(new VarExp("var_c")),
                                new CompoundStm(new IfStm(new VarExp("var_c"),
                                        new CompoundStm(new ReadFileStmt(new VarExp("var_f"), "var_c"), new PrintStm(new VarExp("var_c"))),
                                        new PrintStm(new ConstExp(0))), new CloseRFile(new VarExp("var_f"))))));

        //

        //
        IStatement ex5 = new CompoundStm(
                new OpenRFileStmt("var_f", "openrfiletest.txt"),
                new CompoundStm(
                        new ReadFileStmt(new ArithExp(new VarExp("var_f"), '+', new ConstExp(2)), "var_c"),
                        new CompoundStm(
                                new PrintStm(new VarExp("var_c")),
                                new CompoundStm(
                                        new IfStm(
                                                new VarExp("var_c"),
                                                new CompoundStm(
                                                        new ReadFileStmt(new VarExp("var_f"), "var_c"),
                                                        new PrintStm(new VarExp("var_c"))),
                                                new PrintStm(new ConstExp(0))),
                                        new CloseRFile(new VarExp("var_f")))
                        )
                )
        );

        /**
         *v=10;new(v,20);new(a,22);wH(a,30);print(a);print(rH(a));a=0
         */
        IStatement ex6 =
                new CompoundStm(
                        new AssignmentStm("v", new ConstExp(10)),
                        new CompoundStm(
                                new NewStmt("v", new ConstExp(20)),
                                new CompoundStm(
                                        new NewStmt("a", new ConstExp(22)),
                                        new CompoundStm(
                                                new WriteHeapStmt("a", new ConstExp(30)),
                                                new CompoundStm(
                                                        new PrintStm(new VarExp("a")),
                                                        new CompoundStm(
                                                                new PrintStm(new ReadHeapExp("a")),
                                                                new AssignmentStm("a", new ConstExp(0)))))
                                )
                        )
                );

        // v=6; (while (v-4) print(v);v=v-1); print(v)
        IStatement ex7 = new CompoundStm(
                new AssignmentStm("v", new ConstExp(6)),
                new CompoundStm(
                        new WhileStmt(new ArithExp(new VarExp("v"), '-', new ConstExp(4)),
                                new CompoundStm(
                                        new PrintStm(new VarExp("v")),
                                        new AssignmentStm("v", new ArithExp(new VarExp("v"), '-', new ConstExp(1)))
                                )),
                        new PrintStm(new VarExp("v")))
        );

        /*
        IStatement ex8 =
                new CompoundStm(
                        new AssignmentStm(
                                "v",
                                new ConstExp(10)),
                        new CompoundStm(
                                new NewStmt(
                                        "a",
                                        new ConstExp(22)),
                                new CompoundStm(
                                        new ForkStmt(
                                                new CompoundStm(
                                                        new CompoundStm(
                                                                new WriteHeapStmt(
                                                                        "a",
                                                                        new ConstExp(30)),
                                                                new CompoundStm(
                                                                        new AssignmentStm(
                                                                                "v",
                                                                                new ConstExp(32)),
                                                                        new CompoundStm(
                                                                                new PrintStm(
                                                                                        new VarExp("v")),
                                                                                new PrintStm(
                                                                                        new ReadHeapExp(
                                                                                                "a"))))),
                                                        new PrintStm(
                                                                new ArithExp(
                                                                        new ConstExp(23),
                                                                        '+',
                                                                        new ConstExp(0))))),
                                        new CompoundStm(
                                                new PrintStm(
                                                        new VarExp("v")),
                                                new PrintStm(
                                                        new ReadHeapExp(
                                                                "a"))))));
        */

            /*
            v=10;new(a,22);
            fork(wH(a,30);v=32;print(v);print(rH(a)));
            print(v);print(rH(a))
            */

        IStatement ex8 = new CompoundStm(
                new CompoundStm(
                        new AssignmentStm("v", new ConstExp(10)),
                        new NewStmt("a", new ConstExp(22))
                ),
                new CompoundStm(
                        new ForkStmt(
                                new CompoundStm(
                                        new WriteHeapStmt("a", new ConstExp(30)),
                                        new CompoundStm(
                                                new AssignmentStm("v", new ConstExp(32)),
                                                new CompoundStm(
                                                        new PrintStm(new VarExp("v")),
                                                        new PrintStm(new ReadHeapExp("a"))
                                                )
                                        )
                                )
                        ),
                        new CompoundStm(
                                new PrintStm(new VarExp("v")),
                                new PrintStm(new ReadHeapExp("a"))
                        )
                )
        );


        IRepo repo1 = new Repo();
        ProgramState ps1 = new ProgramState(ex1);
        repo1.addProgramState(ps1);

        // Test to see if multiple program states work
        //ProgramState pss1 = new ProgramState(ex1);
        //repo1.addProgramState(pss1);

        this.ctrl1 = new InterpreterController(repo1);

        IRepo repo2 = new Repo();
        ProgramState ps2 = new ProgramState(ex2);
        repo2.addProgramState(ps2);
        this.ctrl2 = new InterpreterController(repo2);

        IRepo repo3 = new Repo();
        ProgramState ps3 = new ProgramState(ex3);
        repo3.addProgramState(ps3);
        this.ctrl3 = new InterpreterController(repo3);

        IRepo repo4 = new Repo();
        ProgramState ps4 = new ProgramState(ex4);
        repo4.addProgramState(ps4);
        this.ctrl4 = new InterpreterController(repo4);

        IRepo repo5 = new Repo();
        ProgramState ps5 = new ProgramState(ex5);
        repo5.addProgramState(ps5);
        this.ctrl5 = new InterpreterController(repo5);

        IRepo repo6 = new Repo();
        ProgramState ps6 = new ProgramState(ex6);
        repo6.addProgramState(ps6);
        this.ctrl6 = new InterpreterController(repo6);

        IRepo repo7 = new Repo();
        ProgramState ps7 = new ProgramState(ex7);
        repo7.addProgramState(ps7);
        this.ctrl7 = new InterpreterController(repo7);

        IRepo repo8 = new Repo();
        ProgramState ps8 = new ProgramState(ex8);
        repo8.addProgramState(ps8);
        this.ctrl8 = new InterpreterController(repo8);

        //
        // First step always puts the thingies on the exe stack
        //this.ctrl1.executeOneStepTEST();
        //this.ctrl2.executeOneStepTEST();
        //this.ctrl3.executeOneStepTEST();
        //this.ctrl4.executeOneStepTEST();
        //this.ctrl5.executeOneStepTEST();
        //this.ctrl6.executeOneStepTEST();
        //this.ctrl7.executeOneStepTEST();
        //this.ctrl8.executeOneStepTEST();
        //

        this.currentController = ctrl1;
        //this.currentController.executeAllSteps();


        /////////////////////////////////
        // Primary scene GUI
        /////////////////////////////////
        primaryStage.setTitle("MAP Interpreter");

        VBox layout = new VBox();

        // (a) the number of PrgStates as a TextField
        // Why TextField when we only want to display it, not modify it?
        this.noOfPrgStatesText = new Text("noOfPrgStates = " + String.valueOf(this.getControllerForSelectedListViewIndex().getRepo().getProgramStates().size()));
        layout.getChildren().add(noOfPrgStatesText);

        // (b) the HeapTable as a TableView with two columns: address and value
        Text heapTableText = new Text("Heap Table:");
        layout.getChildren().add(heapTableText);

        this.heapTableView = new TableView();
        this.heapTableView.setEditable(false);

        TableColumn<Map.Entry<Integer, Integer>, Number> addressCol = new TableColumn<>("Address");
        addressCol.setCellValueFactory(param -> new ReadOnlyObjectWrapper<>(param.getValue().getKey()));

        TableColumn<Map.Entry<Integer, Integer>, Number> valueCol = new TableColumn<>("Value");
        valueCol.setCellValueFactory(param -> new ReadOnlyObjectWrapper<>(param.getValue().getValue()));

        this.heapTableView.getColumns().setAll(addressCol, valueCol);

        this.heapTableView.setPrefSize(150, 100);
        this.heapTableView.setMaxWidth(150);

        // INSERT HEAPTABLEVIEW DATA
        //this.currentController.executeAllSteps();
        this.updateHeapTableView();

        /////////////
        layout.getChildren().add(this.heapTableView);

        //
        // (c) the Out as a ListView
        //
        Text outputText = new Text("Output:");
        layout.getChildren().add(outputText);

        this.outListView = new ListView<>();
        this.outListView.setPrefSize(150, 100);
        this.outListView.setMaxWidth(150);

        // Called this to test if the data was inserted correctly
        //this.currentController.executeAllSteps();

        this.updateOutListView();

        // Add outListView to layout
        layout.getChildren().add(this.outListView);

        //
        // (d) the FileTable as a TableView with two columns:identifier and file name
        //
        Text fileTableText = new Text("File Table:");
        layout.getChildren().add(fileTableText);

        this.fileTableView = new TableView();
        this.fileTableView.setPrefSize(200, 100);
        this.fileTableView.setMaxWidth(200);
        this.fileTableView.setEditable(false);

        TableColumn<Map.Entry<Integer, Integer>, Number> identifierCol = new TableColumn<>("Identifier");
        identifierCol.setCellValueFactory(param -> new ReadOnlyObjectWrapper<>(param.getValue().getKey()));

        TableColumn<Map.Entry<String, Tuple<String, BufferedReader>>, String> fileNameCol = new TableColumn<>("File  Name");
        fileNameCol.setCellValueFactory(param -> new ReadOnlyObjectWrapper<>(param.getValue().getValue().getFirst()));

        this.fileTableView.getColumns().setAll(identifierCol, fileNameCol);
        this.updateFileTableView();

        layout.getChildren().add(this.fileTableView);

        //
        // (e) the list of PrgState identifiers as a ListView
        //
        layout.getChildren().add(new Text("Program States:"));

        this.programStatesListView = new ListView<>();
        this.programStatesListView.setPrefSize(150, 100);
        this.programStatesListView.setMaxWidth(150);

        this.updateProgramStatesListView();

        layout.getChildren().add(this.programStatesListView);

        //
        // (f) a Table View with two columns: variable name and value, which displays the SymTable
        //
        Text symTableText = new Text("Symbol Table:");
        layout.getChildren().add(symTableText);

        this.symTableView = new TableView();
        this.symTableView.setPrefSize(200, 100);
        this.symTableView.setMaxWidth(200);
        this.symTableView.setEditable(false);

        TableColumn<Map.Entry<String, Integer>, String> varNameCol = new TableColumn<>("Variable");
        varNameCol.setCellValueFactory(param -> new ReadOnlyStringWrapper(param.getValue().getKey()));

        TableColumn<Map.Entry<String, Integer>, Integer> varValueCol = new TableColumn<>("Value");
        varValueCol.setCellValueFactory(param -> new ReadOnlyObjectWrapper<>(param.getValue().getValue()));

        this.symTableView.getColumns().setAll(varNameCol, varValueCol);
        this.updateSymTableView();

        layout.getChildren().add(this.symTableView);

        //
        // (g) a List View which displays the ExeStack of the PrgState whose ID has been
        // selected from the list described at (e). First element of the ListView is a string
        // represenatation of the top of ExeStack, the second element of the ListView
        // represents the second element from the ExeStack and so on.
        //
        layout.getChildren().add(new Text("Execution Stack:"));

        this.exeStackListView = new ListView<>();
        this.exeStackListView.setPrefSize(150, 100);
        this.exeStackListView.setMaxWidth(150);

        this.updateExeStackListView();

        layout.getChildren().add(this.exeStackListView);

        //
        // (h) A button "Run one step" that runs oneStepForAllPrg (you have to design and
        // implement the handler of this button based on the previous method allStep).
        // After each run the displayed information is updated. You may want to write a
        // service which wraps the repository and signals any change of the list of
        // PrgStates (please see the lectures examples).
        //

        this.oneStepBtn = new Button("Execute one step");

        this.oneStepBtn.setOnAction(event -> {
            try {
                // TODO figure out why I need this 2 times
                this.currentController.executeOneStepTEST();
                this.currentController.executeOneStepTEST();

                this.updateHeapTableView();
                this.updateOutListView();
                this.updateFileTableView();
                this.updateSymTableView();
                this.updateExeStackListView();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });

        layout.getChildren().add(oneStepBtn);

        ////////////////////////////////
        Scene scene = new Scene(layout, 500, 500);
        primaryStage.setScene(scene);
        primaryStage.show();

        /////////////////////////////////
        // Second scene GUI
        // A window to select the program that will be executed
        /////////////////////////////////
        StackPane secondLayout = new StackPane();
        Scene secondScene = new Scene(secondLayout, 300, 500);
        Stage secondWindow = new Stage();

        ListView<Text> listView = new ListView<>();

        // ADD TEXT TO LISTVIEW
        Text t1 = new Text(ex1.toString());
        t1.wrappingWidthProperty().bind(listView.widthProperty());

        Text t2 = new Text(ex2.toString());
        t2.wrappingWidthProperty().bind(listView.widthProperty());

        Text t3 = new Text(ex3.toString());
        t3.wrappingWidthProperty().bind(listView.widthProperty());

        Text t4 = new Text(ex4.toString());
        t4.wrappingWidthProperty().bind(listView.widthProperty());

        Text t5 = new Text(ex5.toString());
        t5.wrappingWidthProperty().bind(listView.widthProperty());

        Text t6 = new Text(ex6.toString());
        t6.wrappingWidthProperty().bind(listView.widthProperty());

        Text t7 = new Text(ex7.toString());
        t7.wrappingWidthProperty().bind(listView.widthProperty());

        Text t8 = new Text(ex8.toString());
        t8.wrappingWidthProperty().bind(listView.widthProperty());

        listView.getItems().addAll(t1, t2, t3, t4, t5, t6, t7, t8);
        listView.getSelectionModel().setSelectionMode(SelectionMode.SINGLE);

        // LISTVIEW ON SELECTED INDEX LISTENER LAMBDA
        listView.setOnMouseClicked((event) -> {
            // !!!
            // getSelectedIndex() returns -1 if invalid

            int selectedIndex = listView.getSelectionModel().getSelectedIndex();
            if (selectedIndex != -1)
                currIndex[0] = selectedIndex;

            // (a) the number of PrgStates
            this.noOfPrgStatesText.setText("noOfPrgStates = " + String.valueOf(this.getControllerForSelectedListViewIndex().getRepo().getProgramStates().size()));
            this.currentController = this.getControllerForSelectedListViewIndex();

            //System.out.println("CLICKED ON INDEX " + currIndex[0]); //+ listView.getSelectionModel().getSelectedIndex());

            this.updateHeapTableView();
            this.updateOutListView();
            this.updateFileTableView();
            this.updateProgramStatesListView();
            this.updateSymTableView();
            this.updateExeStackListView();
        });

        secondLayout.getChildren().add(listView);

        secondWindow.setTitle("Runnable programs");
        secondWindow.setScene(secondScene);
        secondWindow.show();
    }
}
