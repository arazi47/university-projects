package View;

import Controller.InterpreterController;
import Model.Expression.*;
import Model.ProgramState;
import Model.Statement.*;
import Model.Statement.HeapStatements.NewStmt;
import Model.Statement.HeapStatements.WriteHeapStmt;
import Model.Utils.MyDictionary;
import Model.Utils.MyList;
import Model.Utils.MyStack;
import Model.Utils.Tuple;
import Repository.IRepo;
import Repository.Repo;

import java.io.BufferedReader;

public class View {
    public static void main(String[] args) {
        // C:\Users\necso\Desktop\926\src\openrfiletest.txt

        // v = 2; print(v)
        IStatement ex1 = new CompoundStm(new AssignmentStm("v",new ConstExp(2)), new PrintStm(new
                VarExp("v")));

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
                        new ReadFileStmt(new ArithExp(new VarExp("var_f"), '+', new ConstExp(0)), "var_c"),
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

        IRepo repo1 = new Repo();
        ProgramState ps1 = new ProgramState(ex1);
        repo1.add(ps1);
        InterpreterController ctrl1 = new InterpreterController(repo1);

        IRepo repo2 = new Repo();
        ProgramState ps2 = new ProgramState(ex2);
        repo2.add(ps2);
        InterpreterController ctrl2 = new InterpreterController(repo2);

        IRepo repo3 = new Repo();
        ProgramState ps3 = new ProgramState(ex3);
        repo3.add(ps3);
        InterpreterController ctrl3 = new InterpreterController(repo3);

        IRepo repo4 = new Repo();
        ProgramState ps4 = new ProgramState(ex4);
        repo4.add(ps4);
        InterpreterController ctrl4 = new InterpreterController(repo4);

        IRepo repo5 = new Repo();
        ProgramState ps5 = new ProgramState(ex5);
        repo5.add(ps5);
        InterpreterController ctrl5 = new InterpreterController(repo5);

        IRepo repo6 = new Repo();
        ProgramState ps6 = new ProgramState(ex6);
        repo6.add(ps6);
        InterpreterController ctrl6 = new InterpreterController(repo6);

        IRepo repo7 = new Repo();
        ProgramState ps7 = new ProgramState(ex7);
        repo7.add(ps7);
        InterpreterController ctrl7 = new InterpreterController(repo7);

        TextMenu menu = new TextMenu();
        menu.addCommand(new ExitCommand("0", "exit"));
        menu.addCommand(new RunExample("1", ex1.toString(), ctrl1));
        menu.addCommand(new RunExample("2", ex2.toString(), ctrl2));
        menu.addCommand(new RunExample("3", ex3.toString(), ctrl3));
        menu.addCommand(new RunExample("4", ex4.toString(), ctrl4));
        menu.addCommand(new RunExample("5", ex5.toString(), ctrl5));
        menu.addCommand(new RunExample("6", ex6.toString(), ctrl6));
        menu.addCommand(new RunExample("7", ex7.toString(), ctrl7));

        menu.show();

        /*
        System.out.println(repo.getCurrentPs());
        while (!mainPs.getExeStack().isEmpty()) {
            System.out.println("1. Execute one command\n2. Execute all commands");
            int option = Integer.valueOf(scanner.nextLine());
            if (option == 1) {
                ctrl.executeCmd(mainPs);
            } else if (option == 2) {
                ctrl.executeAll();
            } else {
                System.out.println("Unknown option entered!");
            }

            System.out.println(repo.getCurrentPs());
        }
        */
    }
}
