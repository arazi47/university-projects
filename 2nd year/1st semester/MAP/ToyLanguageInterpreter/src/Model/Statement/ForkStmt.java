package Model.Statement;

import Model.ProgramState;
import Model.Utils.MyStack;

public class ForkStmt implements IStatement {
    private IStatement stmt;

    public ForkStmt(IStatement stmt) {
        this.stmt = stmt;
    }

    @Override
    public ProgramState execute(ProgramState ps) {
        return new ProgramState(
                this.stmt,
                new MyStack<IStatement>(),
                ps.getOutput(),
                ps.getSymTable().cloneDict(),
                ps.getFileTable(),
                ps.getHeap(),
                ps.getId() * 10);
    }

    @Override
    public String toString() {
        return "fork(" + this.stmt + ")";
    }
}
