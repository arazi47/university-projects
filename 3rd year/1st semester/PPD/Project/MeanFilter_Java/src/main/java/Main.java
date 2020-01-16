import java.io.IOException;

public class Main {

    public static void main(String[] args) {
        long start = System.currentTimeMillis();
        MeanFilter meanFilter = new MeanFilter("test.jpg");
        long end = System.currentTimeMillis();
        System.out.println("Finished algorithm in " + (end - start) + " ms.");
        try {
            meanFilter.writeToFile();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
