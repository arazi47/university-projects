import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Callable;

class ThreadedMatrixMultiplicationFuture extends ThreadedMatrixOperationFuture {
    ThreadedMatrixMultiplicationFuture(Matrix a, Matrix b, Matrix c) {
        super(a, b, c);
    }

    @Override
    public Integer call() {
        for (Coords coords : this.coordsToWorkOn){
            int mul = 0;
            for (int i = 0; i < c.getRows(); ++i){
                mul += (a.getValue(coords.getRow(), i) * b.getValue(i, coords.getCol()));
            }

            this.c.setValue(coords.getRow(), coords.getCol(), mul);
        }

        return 0;
    }
}

class ThreadedMatrixAdditionFuture extends ThreadedMatrixOperationFuture {
    ThreadedMatrixAdditionFuture(Matrix a, Matrix b, Matrix c) {
        super(a, b, c);
    }

    @Override
    public Integer call() {
        for (Coords coords : this.coordsToWorkOn) {
            this.c.setValue(coords.getRow(), coords.getCol(), a.getValue(coords.getRow(), coords.getCol()) + b.getValue(coords.getRow(), coords.getCol()));
        }

        return 0;
    }
}

abstract class ThreadedMatrixOperationFuture implements Callable {
    final Matrix a;
    final Matrix b;
    final Matrix c;
    final List<Coords> coordsToWorkOn;

    ThreadedMatrixOperationFuture(Matrix a, Matrix b, Matrix c) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.coordsToWorkOn = new ArrayList<>();
    }

    void addCoordToWorkOn(int i, int j) {
        this.coordsToWorkOn.add(new Coords(i, j));
    }
}
