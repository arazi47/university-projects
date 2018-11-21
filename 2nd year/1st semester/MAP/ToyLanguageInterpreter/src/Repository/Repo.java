package Repository;

import Model.ProgramState;
import Model.Utils.MyList;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class Repo implements IRepo {
    private List<ProgramState> programStates;
    private int currentPsIndex;

    private String logPath;
    private PrintWriter printWriter;

    public Repo() {
        this.programStates = new ArrayList<>();
        this.currentPsIndex = 0;

        this.logPath = "C:\\Users\\necso\\Desktop\\926\\src\\logfile.txt";
    }

    @Override
    public void addProgramState(ProgramState ps) {
        this.programStates.add(ps);
    }

    //@Override
    //public ProgramState getCurrentPs() {
    //    return this.programStates.get(this.currentPsIndex);
    //}

    @Override
    public void logPrgStateExec(ProgramState ps) {
        try {
            this.printWriter = new PrintWriter(new BufferedWriter(new FileWriter(this.logPath, true)));

            printWriter.println("Program id: " + ps.getId());
            printWriter.println("Execution stack:");
            printWriter.println(ps.getExeStack().toString());
            printWriter.println("Symbol table: ");
            printWriter.println(ps.getSymTable().toString());
            printWriter.println("Output: ");
            printWriter.println(ps.getOutput().toString());
            printWriter.println("File table: ");
            printWriter.println(ps.getFileTable().toString());
            printWriter.println("Heap: ");
            printWriter.println(ps.getHeap().toString());
            printWriter.println("_____________________");
            printWriter.close();
        } catch (java.io.IOException e) {
            System.out.println(e.toString());
        }
    }

    @Override
    public void setProgramStatesList(List<ProgramState> psList) {
        this.programStates = psList;
    }

    @Override
    public List<ProgramState> getProgramStates() {
        return this.programStates;
    }
}
