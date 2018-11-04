package Controller;

import Model.ProgramState;
import Model.Statement.IStatement;
import Model.Utils.MyStack;
import Repository.IRepo;
import Repository.Repo;
import Exception.CustomException;

public class InterpreterController {
    private IRepo repo;

    public InterpreterController(IRepo repo) {
        this.repo = repo;
    }

    public ProgramState executeCmd(ProgramState state) {
        MyStack<IStatement> stack = state.getExeStack();
        if (stack.isEmpty()) {
            throw new CustomException("[Exe stack error] Execution stack is empty!");
        }

        IStatement currentStatement = stack.pop();
        return currentStatement.execute(state);
    }

    public void executeAll() {
        ProgramState state = this.repo.getCurrentPs();
        //System.out.println("ASD");
        try {
            while (!state.getExeStack().isEmpty()) {
                this.executeCmd(state);
                this.repo.logPrgStateExec();
                // TODO display program state here (only if you want to)
                //System.out.println("EXEC COMM");
            }
        } catch (RuntimeException e) {
            System.out.println(e.toString());
        }
    }

    public IRepo getRepo() {
        return this.repo;
    }
}
