package com.company;

import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/**
 * 1. Given a sequence of n numbers, compute the sums of the first k numbers, for each k between 1 and n.
 * Parallelize the computations, to optimize for low latency on a large number of processors. Use at most 2*n
 * additions, but no more than 2*log(n) additions on each computation path from inputs to an output. Example: if
 * the input sequence is 1 5 2 4, then the output should be 1 6 8 12.
 *
 * Used link: https://cs.wmich.edu/gupta/teaching/cs5260/5260Sp15web/lectureNotes/thm14%20-%20parallel%20prefix
 * %20from%20Ottman.pdf
 */
public class Problem1 {

    public static void run(Integer[] s, int nThreads) throws InterruptedException {
        ExecutorService service = Executors.newFixedThreadPool(nThreads);
        //calculate from even positions - bottom up (binary tree)
        int n = s.length;
        for (int d = 0; d < myLog2(n); d++) {
            int totalNumberOfTasks = (int) (n / Math.pow(2, d + 1));
            CountDownLatch latch = new CountDownLatch(totalNumberOfTasks);

            for (int i = 0; i < n; i += Math.pow(2, d + 1)) {
                int finalI = i;
                int finalD = d;
                service.execute(() -> {
                    s[(int) (finalI + Math.pow(2, finalD + 1) - 1)] =
                            s[(int) (finalI + Math.pow(2, finalD) - 1)] + s[(int) (finalI + Math.pow(2, finalD + 1) - 1)];
                    latch.countDown();
                });
            }

            latch.await();
        }

        //System.out.println("After Bottom-Up: ");
        //Main.printArray(s);

        int last = s[n - 1];

        //calculate from odd positions - top down (binary tree)
        s[n - 1] = 0;

        for (int d = myLog2(n) - 1; d >= 0; d--) {
            int taskNumber = (int) (n / Math.pow(2, d + 1));

            CountDownLatch latch = new CountDownLatch(taskNumber);
            for (int i = 0; i < n; i += Math.pow(2, d + 1)) {
                int finalI = i;
                int finalD = d;
                service.execute(() -> {
                    int temp = s[(int) (finalI + Math.pow(2, finalD)) - 1];
                    s[(int) (finalI + Math.pow(2, finalD)) - 1] = s[(int) (finalI + Math.pow(2, finalD + 1)) - 1];
                    s[(int) (finalI + Math.pow(2, finalD + 1)) - 1] += temp;
                    latch.countDown();
                });
            }
            latch.await();
        }

        service.shutdownNow();

        //System.out.println("After Top-Down: ");
        //Main.printArray(s);

        //shift array for result
        Integer[] result = new Integer[n];
        for (int i = 0; i < result.length - 1; i++) {
            result[i] = s[i + 1];
        }
        result[result.length - 1] = last;

        Main.printArray(result);
    }

    public static void runSequential(Integer[] s) {
        //calculate from even positions - bottom up (binary tree)
        int n = s.length;
        for (int d = 0; d <= myLog2(n) - 1; d++) {
            for (int i = 0; i <= n - 1; i += (int) Math.pow(2, d + 1)) {
                s[i + (int) Math.pow(2, d + 1) - 1] += s[i + (int) Math.pow(2, d) - 1];
            }
        }

        //System.out.println("After Bottom-Up: ");
        //Main.printArray(s);

        int last = s[n - 1];

        //calculate from odd positions - top down (binary tree)
        s[n - 1] = 0;

        for (int d = myLog2(n) - 1; d >= 0; d--) {

            for (int i = 0; i <= n - 1; i += (int) Math.pow(2, d + 1)) {
                int temp = s[i + (int) Math.pow(2, d) - 1];
                s[i + ((int) Math.pow(2, d)) - 1] = s[i + ((int) Math.pow(2, d + 1)) - 1];
                s[i + ((int) Math.pow(2, d + 1)) - 1] += temp;
            }
        }

        //System.out.println("After Top-Down: ");
        //Main.printArray(s);

        //shift array for result
        Integer[] result = new Integer[n];
        for (int i = 0; i < result.length - 1; i++) {
            result[i] = s[i + 1];
        }
        result[result.length - 1] = last;

        Main.printArray(result);
    }

    public static int myLog2(int n) {
        return (int) (Math.log(n) / Math.log(2));
    }
}