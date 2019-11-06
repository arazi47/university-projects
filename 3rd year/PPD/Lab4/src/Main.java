import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Main {

    private static int rows = 3, columns = 3;

    private static int[][] A = {
            {1, 1, 1},
            {1, 1, 1,},
            {1, 1, 1}
    };

    private static int[][] B = {
            {1, 1, 1},
            {1, 1, 1,},
            {1, 1, 1}
    };

    private static int[][] C = {
            {1, 1, 1},
            {1, 1, 1,},
            {1, 1, 1}
    };

    private static int[][] AB = new int[rows][columns];
    private static int[][] ABC = new int[rows][columns];
    private static Lock lock = new ReentrantLock();
    private static Condition rowDone = lock.newCondition();
    private static final int noThreads = 4;

    public static void main(String[] args) {
        long start, end;
        start = System.currentTimeMillis();

        ExecutorService esAB = Executors.newFixedThreadPool(noThreads);
        for (int i = 0; i < rows; ++i) {
            Multiplication thread = new Multiplication(i, 1);
            esAB.submit(thread);
        }

        ExecutorService esABC = Executors.newFixedThreadPool(noThreads);
        for (int i = 0; i < rows; ++i) {
            Multiplication thread = new Multiplication(i, 2);
            esABC.submit(thread);
        }

        try {
            if (!esAB.awaitTermination(1, TimeUnit.SECONDS))
                esAB.shutdown();

            if (!esABC.awaitTermination(1, TimeUnit.SECONDS))
                esABC.shutdown();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        end = System.currentTimeMillis();
        System.out.println("Time elapsed (using " + noThreads + " threads): " + (end - start) + " ms.");

        System.out.println("\nA * B = {");
        Main.printMatrix(AB);
        System.out.println("}");

        System.out.println("\nA * B * C = {");
        Main.printMatrix(ABC);
        System.out.println("}");
    }

    private static void printMatrix(int[][] matrix) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    static class Multiplication extends Thread {
        private int row;
        private int type;

        Multiplication(int row, int type) {
            this.row = row;
            this.type = type;
        }

        @Override
        public void run() {
            lock.lock();

            try {
                if (type == 2) {
                    while (!isRowFilled(AB, row)) {
                        rowDone.await();
                    }
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            for (int j = 0; j < rows; ++j) {
                for (int k = 0; k < rows; ++k) {
                    if (type == 1) {
                        AB[row][j] += A[row][k] * B[k][j];
                    } else {
                        ABC[row][j] += AB[row][k] * C[k][j];
                    }
                }
                if (type == 1) {
                    rowDone.signal();
                }
            }
            lock.unlock();
        }
    }

    private static boolean isRowFilled(int[][] matrix, int row) {
        for (int i = 0; i < matrix.length; ++i) {
            if (matrix[row][i] == 0)
                return false;
        }
        return true;
    }
}
