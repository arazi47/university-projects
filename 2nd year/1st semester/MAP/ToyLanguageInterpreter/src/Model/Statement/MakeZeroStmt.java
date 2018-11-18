package Model.Statement;

import Model.ProgramState;

public class MakeZeroStmt implements IStatement {
    private String id;

    public MakeZeroStmt(String id) {
        this.id = id;
    }

    @Override
    public ProgramState execute(ProgramState ps) {
        ps.getSymTable().put(this.id, 0);

        return ps;
    }

    @Override
    public String toString() {
        return "makeZero(" + this.id + ")";
    }
}
