import java.util.ArrayList;
import java.util.List;

class Coords {
    private final int row;
    private final int col;
    Coords(int row, int col) {
        this.row = row;
        this.col = col;
    }

    int getRow() {
        return this.row;
    }

    int getCol() {
        return this.col;
    }
}

class ThreadedMatrixMultiplicationThreadPool extends ThreadedMatrixOperationThreadPool {
    ThreadedMatrixMultiplicationThreadPool(Matrix a, Matrix b, Matrix c) {
        super(a, b, c);
    }

    @Override
    public void run() {
        for (Coords coords : this.coordsToWorkOn){
            int mul = 0;
            for (int i = 0; i < c.getRows(); ++i){
                mul += (a.getValue(coords.getRow(), i) * b.getValue(i, coords.getCol()));
            }

            this.c.setValue(coords.getRow(), coords.getCol(), mul);
        }
    }
}

class ThreadedMatrixAdditionThreadPool extends ThreadedMatrixOperationThreadPool {
    ThreadedMatrixAdditionThreadPool(Matrix a, Matrix b, Matrix c) {
        super(a, b, c);
    }

    @Override
    public void run() {
        for (Coords coords : this.coordsToWorkOn) {
            this.c.setValue(coords.getRow(), coords.getCol(), a.getValue(coords.getRow(), coords.getCol()) + b.getValue(coords.getRow(), coords.getCol()));
        }
    }
}

abstract class ThreadedMatrixOperationThreadPool implements Runnable {
    final Matrix a;
    final Matrix b;
    final Matrix c;
    final List<Coords> coordsToWorkOn;

    ThreadedMatrixOperationThreadPool(Matrix a, Matrix b, Matrix c) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.coordsToWorkOn = new ArrayList<>();
    }

    void addCoordToWorkOn(int i, int j) {
        this.coordsToWorkOn.add(new Coords(i, j));
    }
}
