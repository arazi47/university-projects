package Model.Statement;

import Model.ProgramState;
import Model.Utils.MyStack;

public class CompoundStm implements IStatement {
    private IStatement st1, st2;

    public CompoundStm(IStatement st1, IStatement st2) {
        this.st1 = st1;
        this.st2 = st2;
    }

    @Override
    public ProgramState execute(ProgramState ps) {
        MyStack<IStatement> exeStack = ps.getExeStack();
        exeStack.push(this.st2);
        exeStack.push(this.st1);

        return ps;
    }

    @Override
    public String toString() {
        return "(" + this.st1.toString() + "; " + this.st2.toString() + ")";
    }
}
