package Model.Statement;

import Model.ProgramState;

public class ReturnStmt implements IStatement {
    @Override
    public ProgramState execute(ProgramState ps) {
        ps.getStackSymTable().pop();
        return null;
    }

    @Override
    public String toString() {
        return "return()";
    }
}
