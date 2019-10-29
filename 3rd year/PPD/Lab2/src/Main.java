import java.util.ArrayList;
import java.util.List;

class Main {
    private static Matrix threadedOperation(String op, Matrix a, Matrix b, int noThreads) {
        Matrix c = new Matrix(a.getRows(), a.getCols()); // Result
        List<ThreadedMatrixOperation> threads = new ArrayList<>();
        if (op.equals("add")) {
            // addition
            for (int i = 0; i < noThreads; ++i) {
                threads.add(new ThreadedMatrixAddition(a, b, c));
            }
        } else if (op.equals("mul")) {
            // multiplication
            for (int i = 0; i < noThreads; ++i) {
                threads.add(new ThreadedMatrixMultiplication(a, b, c));
            }
        }

        for (int row = 0; row < c.getRows(); ++row){
            for(int col = 0; col < c.getCols(); ++col){
                threads.get(c.index(row, col) % noThreads).addCoordToWorkOn(row, col);
            }
        }

        for (int i = 0; i < noThreads; i++){
            threads.get(i).start();
        }

        for (int i = 0; i < noThreads; i++){
            try {
                threads.get(i).join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        return c;
    }

    public static void main(String[] args) {
        Matrix a = new Matrix(1000, 1000);
        Matrix b = new Matrix(1000, 1000);
        float start, end; // start and end time for an threadedOperation

        start =  System.nanoTime() / 1000000;
        Matrix c1 = threadedOperation("add", a, b, 1);
        end = System.nanoTime() / 1000000;
        System.out.println("[ADD] Time elapsed: " + (end - start) / 1000 + " seconds, " + 1 + " thread");

        start =  System.nanoTime() / 1000000;
        Matrix c2 = threadedOperation("add", a, b, 4);
        end = System.nanoTime() / 1000000;
        System.out.println("[ADD] Time elapsed: " + (end - start) / 1000 + " seconds, " + 4 + " threads");

        start =  System.nanoTime() / 1000000;
        Matrix c3 = threadedOperation("mul", a, b, 1);
        end = System.nanoTime() / 1000000;
        System.out.println("[MUL] Time elapsed: " + (end - start) / 1000 + " seconds, " + 1 + " thread");

        start =  System.nanoTime() / 1000000;
        Matrix c4 = threadedOperation("mul", a, b, 4);
        end = System.nanoTime() / 1000000;
        System.out.println("[MUL] Time elapsed: " + (end - start) / 1000 + " seconds, " + 4 + " threads");

        start =  System.nanoTime() / 1000000;
        Matrix c5 = threadedOperation("mul", a, b, 8);
        end = System.nanoTime() / 1000000;
        System.out.println("[MUL] Time elapsed: " + (end - start) / 1000 + " seconds, " + 8 + " threads");

        start =  System.nanoTime() / 1000000;
        Matrix c6 = threadedOperation("mul", a, b, 12);
        end = System.nanoTime() / 1000000;
        System.out.println("[MUL] Time elapsed: " + (end - start) / 1000 + " seconds, " + 12 + " threads");
    }
}
