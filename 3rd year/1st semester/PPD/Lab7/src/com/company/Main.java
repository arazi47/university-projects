package com.company;

import java.util.Arrays;
import java.util.Random;

public class Main {

    public static final int arraySize = 1024;
    private static final int exponent = 5;
    private static final int threadCount = 4;
    private static long startTime, endTime; // For performance measurements

    public static void main(String[] args) throws InterruptedException {
        System.out.println("Problem #1:");
        problem1();
        System.out.println("===========================================");
        System.out.println("Problem #2:");
        problem2();
    }

    public static void printElapsedTime(long ms) {
        System.out.println("Elapsed time: " + ms + " ms.");
    }

    private static void problem1() throws InterruptedException {
        Integer[] s = generateRandomArray();
        Integer[] sCopy = Arrays.copyOf(s, s.length);

        printArray(s);
        System.out.println("\nSequential:");
        startTime = System.currentTimeMillis();
        Problem1.runSequential(sCopy);
        endTime = System.currentTimeMillis();
        printElapsedTime(endTime - startTime);

        System.out.println("\nParallelized (" + threadCount + " threads):");
        startTime = System.currentTimeMillis();
        Problem1.run(s, threadCount);
        endTime = System.currentTimeMillis();
        printElapsedTime(endTime - startTime);
    }

    private static void problem2() {
        String[] s = generateBigNumberArray(exponent);
        Problem2 p02 = new Problem2(s);
        System.out.println("Initial list:");
        Main.printArray(s);
        try {
            System.out.println("\nSequential:");
            startTime = System.currentTimeMillis();
            p02.runSequential();
            endTime = System.currentTimeMillis();
            printElapsedTime(endTime - startTime);

            System.out.println("\nParallelized (" + (s.length - 1) + " threads):");
            startTime = System.currentTimeMillis();
            p02.run(threadCount);
            endTime = System.currentTimeMillis();
            printElapsedTime(endTime - startTime);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public static String[] generateBigNumberArray(int powerOfTwo) {
        Random random = new Random();
        //compute the total number of elements from the list of big numbers
        int noOfElements = (int) Math.pow(2, powerOfTwo);
        String[] generatedS = new String[noOfElements];
        //each element from the list is set to a generated a big number
        for (int j = 0; j < noOfElements; j++) {
            StringBuilder bigNumber = new StringBuilder();
            //choose a random size of the big number between 5 and 15
            int bigNoLength = random.nextInt(16) + 5;
            //generate the digits of the big number
            for (int i = 0; i < bigNoLength; i++) {
                bigNumber.append(random.nextInt(10));
            }
            generatedS[j] = bigNumber.toString();
        }
        return generatedS;
    }

    private static Integer[] generateRandomArray() {
        Random random = new Random();
        Integer[] s = new Integer[arraySize];
        for (int i = 0; i < arraySize; i++) {
            s[i] = random.nextInt(999999);
        }
        return s;
    }

    public static void printArray(Object[] s) {
        StringBuilder str = new StringBuilder("s: ");
        for (int i = 0; i < s.length; i++) {
            str.append(s[i]).append(" ");
        }
        System.out.println(str.toString());
    }
}