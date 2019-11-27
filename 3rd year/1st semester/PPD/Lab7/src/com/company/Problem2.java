package com.company;

import java.util.LinkedList;
import java.util.Queue;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/**
 * 2. Add n big numbers. We want the result to be obtained digit by digit, starting with the least significant one,
 * and as soon as possible. For this reason, you should use n-1 threads, each adding two numbers. Each thread should
 * pass the result to the next thread. Arrange the threads in a binary tree. Each thread should pass the sum to the
 * next thread through a queue, digit by digit.
 */
public class Problem2 {
    private String[] s;

    public Problem2(String[] s) {
        this.s = s;
    }

    public static int charToInt(char c) {
        return Integer.parseInt(Character.toString(c));
    }

    public static Queue<Integer> QueueDigits(String bigNo) {
        Queue<Integer> queue = new LinkedList<>();
        for (int i = bigNo.length() - 1; i >= 0; i--) {
            char c = bigNo.charAt(i);
            queue.add(charToInt(c));
        }
        return queue;
    }

    public static int getNextDigit(Queue<Integer> queue) {
        if (queue.isEmpty())
            return 0;
        else
            return queue.remove();
    }

    public static void printQueueAsNumber(Queue<Integer> queue) {
        StringBuilder sb = new StringBuilder();
        for (Integer i :
                queue) {
            sb.append(i);
        }
        System.out.println(sb.reverse());
    }

    public static Queue<Integer> addTwo(Queue<Integer> left, Queue<Integer> right) {
        Queue<Integer> result = new LinkedList<>();
        int carry = 0;
        while (!left.isEmpty() || !right.isEmpty()) {
            int sum = getNextDigit(left) + getNextDigit(right) + carry;
            result.add(sum % 10);
            carry = sum / 10;
        }
        if (carry != 0) {
            result.add(carry);
        }
        return result;
    }

    public void runSequential() {
        //transform the list of strings to list of queues
        Queue<Integer>[] queues = new Queue[s.length];
        for (int i = 0; i < s.length; i++) {
            queues[i] = QueueDigits(s[i]);
        }

        for (int d = 0; d < Problem1.myLog2(queues.length); d++) {
            for (int i = 0; i < queues.length; i += Math.pow(2, d + 1)) {
                int finalI = i;
                int finalD = d;
                queues[(int) (finalI + Math.pow(2, finalD + 1) - 1)] =
                        addTwo(queues[(int) (finalI + Math.pow(2, finalD) - 1)],
                                queues[(int) (finalI + Math.pow(2, finalD + 1) - 1)]);
            }
        }

        Queue<Integer> result = queues[queues.length - 1];
        printQueueAsNumber(result);
    }

    public void run(int threadCount) throws InterruptedException {
        //transform the list of strings to list of queues
        Queue<Integer>[] queues = new Queue[s.length];
        for (int i = 0; i < s.length; i++) {
            queues[i] = QueueDigits(s[i]);
        }

        ExecutorService service = Executors.newFixedThreadPool(threadCount);

        for (int d = 0; d < Problem1.myLog2(queues.length); d++) {
            int totalNumberOfTasks = (int) (queues.length / Math.pow(2, d + 1));
            CountDownLatch latch = new CountDownLatch(totalNumberOfTasks);

            for (int i = 0; i < queues.length; i += Math.pow(2, d + 1)) {
                int finalI = i;
                int finalD = d;
                service.execute(() -> {
                    queues[(int) (finalI + Math.pow(2, finalD + 1) - 1)] =
                            addTwo(queues[(int) (finalI + Math.pow(2, finalD) - 1)],
                                    queues[(int) (finalI + Math.pow(2, finalD + 1) - 1)]);
                    latch.countDown();
                });
            }

            latch.await();
        }
        service.shutdownNow();
        Queue<Integer> result = queues[queues.length - 1];
        printQueueAsNumber(result);
    }
}