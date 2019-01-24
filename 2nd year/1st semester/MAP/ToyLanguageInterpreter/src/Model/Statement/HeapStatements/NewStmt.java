package Model.Statement.HeapStatements;

import Model.Expression.IExpression;
import Model.ProgramState;
import Model.Statement.IStatement;

import java.beans.Expression;

public class NewStmt implements IStatement {
    private String var;
    private IExpression exp;

    public NewStmt(String var, IExpression exp) {
        this.var = var;
        this.exp = exp;
    }

    @Override
    public ProgramState execute(ProgramState ps) {
        int result = this.exp.evaluate(ps.getTopSymTable(), ps.getHeap());
        int loc = ps.getHeap().allocate(result);
        ps.getTopSymTable().put(var, loc);

        return null;
    }

    @Override
    public String toString() {
        return "newStmt(" + this.var + ", " + this.exp.toString() + ")";
    }
}
