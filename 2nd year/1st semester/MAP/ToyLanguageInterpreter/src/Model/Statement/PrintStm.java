package Model.Statement;

import Model.Expression.IExpression;
import Model.ProgramState;
import Model.Utils.MyList;

import java.beans.Expression;

public class PrintStm implements IStatement {
    private IExpression exp;

    public PrintStm(IExpression exp) {
        this.exp = exp;
    }

    @Override
    public ProgramState execute(ProgramState ps) {
        MyList<Integer> output = ps.getOutput();
        output.add(this.exp.evaluate(ps.getSymTable(), ps.getHeap()));

        return null;
    }

    @Override
    public String toString() {
        return "print(" + this.exp.toString() + ")";
    }
}
