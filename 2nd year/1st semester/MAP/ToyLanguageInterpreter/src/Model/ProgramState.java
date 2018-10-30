package Model;

import Model.Statement.IStatement;
import Model.Utils.*;

import java.io.BufferedReader;

public class ProgramState {
    private MyStack<IStatement> exeStack;
    private MyList<Integer> output;
    private MyDictionary<String, Integer> symTable;
    private IStatement program;

    private MyDictionary<Integer, Tuple<String, BufferedReader>> fileTable;

    public ProgramState(MyStack<IStatement> exeStack,
                        MyList<Integer> output,
                        MyDictionary<String, Integer> symTable,
                        IStatement program,
                        MyDictionary<Integer, Tuple<String, BufferedReader>> fileTable) {
        this.exeStack = exeStack;
        this.output = output;
        this.symTable = symTable;
        this.program = program;
        this.fileTable = fileTable;

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

    public void setProgram(IStatement prg) {
        this.program = prg;
    }
    public IStatement getProgram() {
        return this.program;
    }

    public void setFileTable(MyDictionary<Integer, Tuple<String, BufferedReader>> fileTable) {
        this.fileTable = fileTable;
    }

    public MyDictionary<Integer, Tuple<String, BufferedReader>> getFileTable() {
        return this.fileTable;
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
