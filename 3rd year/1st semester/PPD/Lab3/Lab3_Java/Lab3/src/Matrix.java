import java.util.Random;

class Matrix {
    private final int[][] matrix;
    private final int rows;
    private final int cols;

    Matrix(int rows, int cols) {
        this.rows = rows;
        this.cols = cols;
        this.matrix = new int[rows][cols];

        Random random = new Random();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // Generate a number between 1 and 100
                this.matrix[i][j] = 2; //random.nextInt(100) + 1;
            }
        }
    }

    int getValue(int i, int j) {
        return this.matrix[i][j];
    }

    void setValue(int i, int j, int value) {
        this.matrix[i][j] = value;
    }

    int getRows() {
        return rows;
    }

    int getCols() {
        return cols;
    }

    public String toString() {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < this.rows; ++i) {
            for (int j = 0; j < this.cols; ++j) {
                result.append(this.matrix[i][j]).append(" ");
            }

            result.append("\n");
        }

        return result.toString();
    }

    int index(int row, int col) {
        return row * this.cols + col;
    }
}
