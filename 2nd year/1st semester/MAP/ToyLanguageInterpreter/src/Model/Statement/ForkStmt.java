package Model.Statement;

import Model.ProgramState;
import Model.Utils.IDictionary;
import Model.Utils.MyDictionary;
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
                ps.copyStackSymTable(),
                //ps.getStackSymTable(),
                ps.getFileTable(),
                ps.getProcTable().cloneDict(),
                ps.getHeap(),
                ps.getId() * 10);
    }

    @Override
    public String toString() {
        return "fork(" + this.stmt + ")";
    }
}
