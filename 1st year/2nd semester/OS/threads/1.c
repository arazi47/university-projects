#include <stdio.h>
#include <pthread.h>

#define MAX_THREADS 100

// thread start routine
void* f(void* a) {
	int k = *(int*)a;
	printf("Thread no %d\n", k);

	return NULL;
}

int main() {
	pthread_t t[MAX_THREADS];
	int i;
	for (i = 0; i < MAX_THREADS; ++i) {
		pthread_create(&t[i], NULL, f, &i);
	}

	for (i = 0; i < MAX_THREADS; ++i) {
		pthread_join(t[i], NULL);
	}

	return 0;
}

