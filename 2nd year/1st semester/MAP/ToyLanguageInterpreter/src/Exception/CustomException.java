package Exception;

public class CustomException extends RuntimeException {
    private String exception;

    public CustomException(String exception) {
        super();
        this.exception = exception;
    }

    public String toString() {
        return this.exception;
    }
}