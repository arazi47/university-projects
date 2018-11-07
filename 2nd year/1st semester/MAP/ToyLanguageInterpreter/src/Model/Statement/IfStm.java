package Model.Statement;

import Model.Expression.IExpression;
import Model.ProgramState;

public class IfStm implements IStatement {
    private IExpression exp;
    private IStatement st1, st2;

    public IfStm(IExpression exp, IStatement st1, IStatement st2) {
        this.exp = exp;
        this.st1 = st1;
        this.st2 = st2;
    }

    @Override
    public ProgramState execute(ProgramState ps) {
        int result = this.exp.evaluate(ps.getSymTable(), ps.getHeap());

        if (result != 0) {
            this.st1.execute(ps);
        } else {
            this.st2.execute(ps);
        }

        return ps;
    }

    @Override
    public String toString() {
        return "if " + this.exp.toString() + " then " + this.st1.toString() + " else " + this.st2.toString();
    }
}
