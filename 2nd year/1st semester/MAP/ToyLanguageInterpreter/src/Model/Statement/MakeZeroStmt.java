package Model.Statement;

import Model.ProgramState;

public class MakeZeroStmt implements IStatement {
    private String id;

    public MakeZeroStmt(String id) {
        this.id = id;
    }

    @Override
    public ProgramState execute(ProgramState ps) {
        ps.getTopSymTable().put(this.id, 0);

        return null;
    }

    @Override
    public String toString() {
        return "makeZero(" + this.id + ")";
    }
}
