package Model.Statement;

import Model.Expression.IExpression;
import Model.ProgramState;
import Model.Utils.MyList;
import Model.Utils.MyStack;

public class WhileStmt implements IStatement {
    private IExpression exp;
    private IStatement stmt;

    public WhileStmt(IExpression exp, IStatement stmt) {
        this.exp = exp;
        this.stmt = stmt;
    }

    @Override
    public ProgramState execute(ProgramState ps) {
        MyStack<IStatement> exeStack = ps.getExeStack();

        if (this.exp.evaluate(ps.getSymTable(), ps.getHeap()) != 0) {
            exeStack.push(this);
            exeStack.push(stmt);
        }

        return ps;
    }

    @Override
    public String toString() {
        return "while(" + this.exp.toString() + ") do " + this.stmt.toString() + " end";
    }
}
