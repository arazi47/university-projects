import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.FutureTask;

class Main {
    private static Matrix threadedOperationThreadPool(String op, Matrix a, Matrix b, int noTasks, int noThreads) {
        Matrix c = new Matrix(a.getRows(), a.getCols()); // Result
        List<ThreadedMatrixOperationThreadPool> tasks = new ArrayList<>();
        if (op.equals("add")) {
            // addition
            for (int i = 0; i < noTasks; ++i) {
                tasks.add(new ThreadedMatrixAdditionThreadPool(a, b, c));
            }
        } else if (op.equals("mul")) {
            // multiplication
            for (int i = 0; i < noTasks; ++i) {
                tasks.add(new ThreadedMatrixMultiplicationThreadPool(a, b, c));
            }
        }

        for (int row = 0; row < c.getRows(); ++row){
            for(int col = 0; col < c.getCols(); ++col){
                tasks.get(c.index(row, col) % noTasks).addCoordToWorkOn(row, col);
            }
        }

        ExecutorService pool = Executors.newFixedThreadPool(noThreads);

        for (ThreadedMatrixOperationThreadPool task : tasks){
            pool.execute(task);
        }

        pool.shutdown();

        return c;
    }

    private static Matrix threadedOperationFuture(String op, Matrix a, Matrix b, int noTasks) {
        Matrix c = new Matrix(a.getRows(), a.getCols()); // Result
        List<ThreadedMatrixOperationFuture> callables = new ArrayList<>();
        if (op.equals("add")) {
            // addition
            for (int i = 0; i < noTasks; ++i) {
                callables.add(new ThreadedMatrixAdditionFuture(a, b, c));
            }
        } else if (op.equals("mul")) {
            // multiplication
            for (int i = 0; i < noTasks; ++i) {
                callables.add(new ThreadedMatrixMultiplicationFuture(a, b, c));
            }
        }

        for (int row = 0; row < c.getRows(); ++row){
            for(int col = 0; col < c.getCols(); ++col){
                callables.get(c.index(row, col) % noTasks).addCoordToWorkOn(row, col);
            }
        }

        List<FutureTask> tasks = new ArrayList<>();

        for (ThreadedMatrixOperationFuture callable : callables) {
            tasks.add(new FutureTask(callable));
        }

        for (FutureTask task : tasks) {
            Thread thread = new Thread(task);
            thread.start();
        }

        for (FutureTask task : tasks) {
            try {
                task.get();
            } catch (InterruptedException | ExecutionException e) {
                e.printStackTrace();
            }
        }

        return c;
    }

    public static void main(String[] args) {
        Matrix a = new Matrix(1000, 1000);
        Matrix b = new Matrix(1000, 1000);
        float start, end; // start and end time for an threadedOperationThreadPool

        start =  System.nanoTime() / 1000000;
        Matrix c1 = threadedOperationThreadPool("add", a, b,50, 1);
        end = System.nanoTime() / 1000000;
        System.out.println("[ADD] Time elapsed: " + (end - start) / 1000 + " seconds, " + 1 + " thread");

        start =  System.nanoTime() / 1000000;
        Matrix c2 = threadedOperationThreadPool("add", a, b, 50, 4);
        end = System.nanoTime() / 1000000;
        System.out.println("[ADD] Time elapsed: " + (end - start) / 1000 + " seconds, " + 4 + " threads");

        start =  System.nanoTime() / 1000000;
        Matrix c3 = threadedOperationThreadPool("mul", a, b, 50, 1);
        end = System.nanoTime() / 1000000;
        System.out.println("[MUL] Time elapsed: " + (end - start) / 1000 + " seconds, " + 1 + " thread");

        start =  System.nanoTime() / 1000000;
        Matrix c4 = threadedOperationThreadPool("mul", a, b, 50, 4);
        end = System.nanoTime() / 1000000;
        System.out.println("[MUL] Time elapsed: " + (end - start) / 1000 + " seconds, " + 4 + " threads");

        System.out.println("===================================================================================");

        start =  System.nanoTime() / 1000000;
        Matrix c7 = threadedOperationFuture("add", a, b,50);
        end = System.nanoTime() / 1000000;
        System.out.println("[ADD] Time elapsed: " + (end - start) / 1000 + " seconds, " + 1 + " thread");

        start =  System.nanoTime() / 1000000;
        Matrix c9 = threadedOperationFuture("mul", a, b, 50);
        end = System.nanoTime() / 1000000;
        System.out.println("[MUL] Time elapsed: " + (end - start) / 1000 + " seconds, " + 1 + " thread");
    }
}
