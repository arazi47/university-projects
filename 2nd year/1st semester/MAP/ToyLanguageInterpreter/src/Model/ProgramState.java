package Model;

import Model.Statement.IStatement;
import Model.Utils.*;

public class ProgramState {
    private MyStack<IStatement> exeStack;
    private MyList<Integer> output;
    private MyDictionary<String, Integer> symTable;
    private IStatement program;

    public ProgramState(MyStack<IStatement> exeStack,
                        MyList<Integer> output,
                        MyDictionary<String, Integer> symTable,
                        IStatement program) {
        this.exeStack = exeStack;
        this.output = output;
        this.symTable = symTable;
        this.program = program;

        this.exeStack.push(this.program);
    }

    public MyDictionary<String, Integer> getSymTable() {
        return this.symTable;
    }

    public void setSymTable(MyDictionary<String, Integer> symTable) {
        this.symTable = symTable;
    }

    public MyStack<IStatement> getExeStack() {
        return this.exeStack;
    }

    public void setExeStack(MyStack<IStatement> exeStack) {
        this.exeStack = exeStack;
    }

    public MyList<Integer> getOutput() {
        return this.output;
    }

    public void setOutput(MyList<Integer> output) {
        this.output = output;
    }

    void setProgram(IStatement prg) {
        this.program = prg;
    }

    IStatement getProgram() {
        return this.program;
    }

    public String toString() {
        String s = "";
        s += "exeStack:\n";
        s += this.exeStack.toString();
        s += "\nsymTable:";
        s += this.symTable.toString();
        s += "\noutput:";
        s += this.output.toString();
        s += "\n--------------------------------\n";

        return s;
    }


}
