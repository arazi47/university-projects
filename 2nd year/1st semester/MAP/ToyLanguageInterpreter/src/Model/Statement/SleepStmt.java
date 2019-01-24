package Model.Statement;

import Model.Expression.ConstExp;
import Model.Expression.IExpression;
import Model.ProgramState;
import Model.Utils.MyList;
import Model.Utils.MyStack;

public class SleepStmt implements IStatement {
    private IExpression exp;

    public SleepStmt(IExpression exp) {
        this.exp = exp;
    }

    @Override
    public ProgramState execute(ProgramState ps) {
        MyStack<IStatement> exeStack = ps.getExeStack();

        int result = this.exp.evaluate(ps.getTopSymTable(), ps.getHeap());

        if (result != 0) {
            exeStack.push(new SleepStmt(new ConstExp(result - 1)));
        }

        return null;
    }

    @Override
    public String toString() {
        return "sleep(" + this.exp.toString() + ")";
    }
}
