package Controller;

import Model.ProgramState;
import Model.Statement.IStatement;
import Model.Utils.MyList;
import Model.Utils.MyStack;
import Repository.IRepo;
import Exception.CustomException;

import java.util.Collection;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.stream.Collectors;

public class InterpreterController {
    private IRepo repo;
    private ExecutorService executor;

    public InterpreterController(IRepo repo) {
        this.repo = repo;
    }

    /*
    public ProgramState executeCmd(ProgramState state) {
        MyStack<IStatement> stack = state.getExeStack();
        if (stack.isEmpty()) {
            throw new CustomException("[Exe stack error] Execution stack is empty!");
        }

        IStatement currentStatement = stack.pop();
        return currentStatement.execute(state);
    }
    */

    /*
    public void executeAll() {
        ProgramState state = this.repo.getCurrentPs();
        //System.out.println("ASD");
        try {
            while (!state.getExeStack().isEmpty()) {
                this.executeCmd(state);
                state.getHeap().setMap(conservativeGarbageCollector(state.getSymTable().values(), state.getHeap().getMap()));
                this.repo.logPrgStateExec();
                // TODO display program state here (only if you want to)
                //System.out.println("EXEC COMM");
            }
        } catch (RuntimeException e) {
            System.out.println(e.toString());
        }
    }
    */

    public void executeAllSteps() throws java.lang.InterruptedException {
        this.executor = Executors.newFixedThreadPool(2);

        List<ProgramState> prgList = removeCompletedPrg(this.repo.getProgramStates());

        // If this is not here, in the log file
        // The first log along with the execution stack will not be printed
        prgList.forEach(this.repo::logPrgStateExec);

        while (prgList.size() > 0) {
            // Garbage collector, if I ever feel like it
            //state.getHeap().setMap(conservativeGarbageCollector(state.getSymTable().values(), state.getHeap().getMap()));

            this.oneStepForAllPrograms(prgList);

            // Remove completed programs
            prgList = this.removeCompletedPrg(this.repo.getProgramStates());
        }

        this.executor.shutdownNow();

        // Close opened files for each program state
        this.repo.getProgramStates().forEach(
                (ps) -> {
                    ps.getFileTable().values()
                            .forEach((e) -> {
                                try {
                                    e.getSecond().close();
                                } catch (java.io.IOException ex) {
                                    System.out.println(ex);
                                }
                            });
                }
        );

        //this.repo.setProgramStatesList(prgList);
    }

    public void executeOneStepTEST() throws java.lang.InterruptedException {
        this.executor = Executors.newFixedThreadPool(2);

        //List<ProgramState> prgList = removeCompletedPrg(this.repo.getProgramStates());
        List<ProgramState> prgList = this.repo.getProgramStates();

        // If this is not here, in the log file
        // The first log along with the execution stack will not be printed
        prgList.forEach(this.repo::logPrgStateExec);

        if (prgList.size() > 0) {
            // Garbage collector, if I ever feel like it
            //state.getHeap().setMap(conservativeGarbageCollector(state.getSymTable().values(), state.getHeap().getMap()));

            this.oneStepForAllPrograms(prgList);

            // Execute one step, not one step for all programs
            //prgList.get(0).executeCmd();

            // Remove completed programs
            //prgList = this.removeCompletedPrg(this.repo.getProgramStates());
        }

        this.executor.shutdownNow();

        // Close opened files for each program state
        this.repo.getProgramStates().forEach(
                (ps) -> {
                    ps.getFileTable().values()
                            .forEach((e) -> {
                                try {
                                    e.getSecond().close();
                                } catch (java.io.IOException ex) {
                                    System.out.println(ex);
                                }
                            });
                }
        );

        //this.repo.setProgramStatesList(prgList);
    }

    public IRepo getRepo() {
        return this.repo;
    }

    public Map<Integer,Integer> conservativeGarbageCollector(Collection<Integer> symTableValues, Map<Integer, Integer> heap) {
        return heap.entrySet()
                .stream()
                .filter(e->symTableValues.contains(e.getKey()))
                .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
    }

    public List<ProgramState> removeCompletedPrg(List<ProgramState> inPrgList) {
        return inPrgList.stream()
                .filter(ProgramState::isNotCompleted)
                .collect(Collectors.toList());
    }

    public void oneStepForAllPrograms(List<ProgramState> prgList) throws java.lang.InterruptedException {
        //prgList.forEach(this.repo::logPrgStateExec);

        List<Callable<ProgramState>> callList = prgList.stream()
                .map((ProgramState p) -> (Callable<ProgramState>)(p::executeCmd))
                .collect(Collectors.toList());

        List<ProgramState> newPrgList = executor.invokeAll(callList).stream()
                .map(future -> {
                    try {
                        return future.get();
                    } catch (Exception e) {
                        System.out.println(e);
                    }

                    return null;
                })
                // p -> p != null
                .filter(Objects::nonNull)
                .collect(Collectors.toList());

        prgList.addAll(newPrgList);
        //this.repo.setProgramStatesList(prgList);
        prgList.forEach(this.repo::logPrgStateExec);
    }
}
