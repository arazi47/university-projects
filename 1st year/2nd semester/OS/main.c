#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

/*
// Sum from 1 to 100 in 10 threads, each adding 10 to the total sum
#define THREADS 10
#define NMAX 100

const int INT_DIF = NMAX / THREADS;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
int sum = 0;

void *f(void *a) {
    int n = (int)a;
    for (int i = n + 1; i <= n + INT_DIF; ++i) {
        pthread_mutex_lock(&mtx);
        sum += i;
        pthread_mutex_unlock(&mtx);
    }

    return NULL;
}

int main() {
    pthread_t t[THREADS];

    for (int i = 0; i < THREADS; ++i) {
        int n = INT_DIF * i;
        pthread_create(&t[i], NULL, f, (void*)n);
    }

    for (int i = 0; i < THREADS; ++i) {
        pthread_join(t[i], NULL);
    }

    printf("Sum: %d\n", sum);
    return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

// Thread 1: sum of the first first half of the array
// Thread 2: sum of the second half of the array
//int numbers[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int numbers[10];
int sum = 0;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void *f(void *a) {
    int half = (int)a;

    // Sum of first half
    if (half == 0) {
        for (int i = 0; i < (sizeof(numbers) / sizeof(int)) / 2; ++i) {
            pthread_mutex_lock(&mtx);
            sum += numbers[i];
            pthread_mutex_unlock(&mtx);
        }
    }
    // Sum of second half
    else {
        for (int i = (sizeof(numbers) / sizeof(int)) / 2; i < sizeof(numbers) / sizeof(int); ++i) {
            pthread_mutex_lock(&mtx);
            sum += numbers[i];
            pthread_mutex_unlock(&mtx);
        }
    }

    return NULL;
}

int main() {
    pthread_t t1, t2;
    FILE *fp = fopen("test.txt", "r");

    int i = 0;
    int num;
    while (!feof(fp)) {
        fscanf(fp, "%d", &num);
        numbers[i++] = num;
    }

    pthread_create(&t1, NULL, f, (void*)(0));
    pthread_create(&t2, NULL, f, (void*)(1));

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Sum: %d\n", sum);

    return 0;
}
*/

/*
// Input a number "g"
// Init 5 threads
// Each thread will decrease g by a random number between 0-9 until g <= 0
int g;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void *f(void *a) {
    int threadIndex = (int)a;
    srand(time(NULL));
    int k = rand() % 10;

    if (g > 0) {
        pthread_mutex_lock(&mtx);
        g -= k;
        pthread_mutex_unlock(&mtx);

        printf("Thread %d decreased g by %d and now g is %d\n", threadIndex, k, g);
    }

    return NULL;
}

int main() {
    printf("Give g: ");
    scanf("%d", &g);

    pthread_t t[5];

    for (int i = 0; i < 5; ++i) {
        pthread_create(&t[i], NULL, f, (void*)(i));
    }

    for (int i = 0; i < 5; ++i) {
        pthread_join(t[i], NULL);
    }

    return 0;
}
*/

int g = 0;
int n;
int total = 0;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void *f(void *a) {
    if (g < n) {
        int fact = 1;
        if (g == 0) {
            fact = 1;
        } else {
            for (int i = 1; i <= g; ++i) {
                fact *= i;
            }
            //printf("for g %d Fact is %d\n", g, fact);
        }

        pthread_mutex_lock(&mtx);
        printf("for g %d Fact is %d\n", g, fact);
        ++g;
        total += fact;
        //printf("g = %d, %d was added to sum, sum is now %d\n", g - 1, fact, total);
        pthread_mutex_unlock(&mtx);
    }

    return NULL;
}

int main() {
    printf("Give n: ");
    scanf("%d", &n);

    pthread_t t[5];

    for (int i = 0; i < 5; ++i) {
        pthread_create(&t[i], NULL, f, NULL);
    }

    for (int i = 0; i < 5; ++i) {
        pthread_join(t[i], NULL);
    }

    return 0;
}