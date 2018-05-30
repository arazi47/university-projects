/*
 * Read "MAXNUM" numbers, then init 2 threads which add the numbers to the global variable "sum"
 * Thread 1: 0 - MAXNUM / 2 - 1
 * Thread 2: MAXNUM / 2 - MAXNUM
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define MAXNUM 100

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

int numbers[MAXNUM];
int sum = 0;

void readNumbers() {
    FILE *file = fopen("test.txt", "r");

    int i = 0;
    while (i < MAXNUM) {
        fscanf(file, "%d", &numbers[i++]);
    }
}

void readNumbersFromBinaryFile() {
    int fd = open("test.txt", O_RDONLY);
    if (fd < 0) {
        perror("error fd");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (i < MAXNUM) {
        read(fd, &numbers[i], 2);
        ++i;
    }
}

void printNumbers() {
    for (int i = 0; i < MAXNUM; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

void *f(void *a) {
    int threadIndex = (int)(a);

    int startIndex = threadIndex == 0 ? 0 : MAXNUM / 2;
    int endIndex = threadIndex == 0 ? MAXNUM / 2 : MAXNUM;

    //printf("thread %d first = %d second = %d\n", threadIndex, first, second);

    for (int i = startIndex; i < endIndex; ++i) {
        pthread_mutex_lock(&mtx);
        sum += numbers[i];
        pthread_mutex_unlock(&mtx);
    }

    return NULL;
}

int main() {
    readNumbersFromBinaryFile();

    pthread_t t1, t2;

    pthread_create(&t1, NULL, f, (void*)(0));
    pthread_create(&t2, NULL, f, (void*)(1));

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Sum is %d.\n", sum);

    return 0;
}

