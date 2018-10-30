package Exception;

public class StackException extends RuntimeException {
    private String exception;

    public StackException(String exception) {
        super();
        this.exception = exception;
    }

    public String toString() {
        return this.exception;
    }
}