package Model.Statement.HeapStatements;

import Model.Expression.IExpression;
import Model.ProgramState;
import Model.Statement.IStatement;

public class WriteHeapStmt implements IStatement {
    private String id;
    private IExpression exp;

    public WriteHeapStmt(String id, IExpression exp) {
        this.id = id;
        this.exp = exp;
    }

    @Override
    public ProgramState execute(ProgramState ps) {
        Integer var_val = ps.getSymTable().get(this.id);

        if (var_val == null) {
            //throw new Exception.CustomException("Unknown variable exception @TODO create a new one here!");
        }

        int val = this.exp.evaluate(ps.getSymTable(), ps.getHeap());
        ps.getHeap().putAddr(var_val, val);

        return ps;
    }

    @Override
    public String toString() {
        return "writeHeap(" + this.id + ", " + this.exp.toString() + ")";
    }
}
