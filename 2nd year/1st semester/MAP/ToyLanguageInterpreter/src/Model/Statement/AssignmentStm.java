package Model.Statement;

import Model.Expression.IExpression;
import Model.ProgramState;
import Model.Utils.MyDictionary;

public class AssignmentStm implements IStatement {
    private String varName;
    private IExpression expr;

    public AssignmentStm(String varName, IExpression expr) {
        this.varName = varName;
        this.expr = expr;
    }

    @Override
    public ProgramState execute(ProgramState ps) {
        MyDictionary<String, Integer> st = ps.getSymTable();
        st.put(this.varName, this.expr.evaluate(st, ps.getHeap()));

        return ps;
    }

    @Override
    public String toString() {
        return this.varName + " = " + this.expr.toString();
    }
}
