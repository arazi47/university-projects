package Repository;

import Model.ProgramState;
import Model.Utils.MyList;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;

public class Repo implements IRepo {
    private MyList<ProgramState> programStates;
    private int currentPsIndex;

    private String logPath;
    private PrintWriter printWriter;

    public Repo() {
        this.programStates = new MyList<>();
        this.currentPsIndex = 0;

        this.logPath = "C:\\Users\\necso\\Desktop\\926\\src\\logfile.txt";
    }

    @Override
    public void add(ProgramState ps) {
        this.programStates.add(ps);
    }

    @Override
    public ProgramState getCurrentPs() {
        return this.programStates.get(this.currentPsIndex);
    }

    @Override
    public void logPrgStateExec() {
        try {
            this.printWriter = new PrintWriter(new BufferedWriter(new FileWriter(this.logPath, true)));

            printWriter.println("Execution stack:");
            printWriter.println(this.getCurrentPs().getExeStack().toString());
            printWriter.println("Symbol table: ");
            printWriter.println(this.getCurrentPs().getSymTable().toString());
            printWriter.println("Output: ");
            printWriter.println(this.getCurrentPs().getOutput().toString());
            printWriter.println("File table: ");
            printWriter.println(this.getCurrentPs().getFileTable().toString());
            printWriter.println("_____________________");
            printWriter.close();
        } catch (java.io.IOException e) {
            System.out.println(e.toString());
        }
    }
}
