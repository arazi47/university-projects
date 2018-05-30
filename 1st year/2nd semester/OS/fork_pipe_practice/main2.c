#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define READ 0
#define WRITE 1

int main() {
	int childPipe[2], parentPipe[2];

	int initNum;
	printf("Give initial number: ");
	scanf("%d", &initNum);

	while (1) {
		if (pipe(childPipe) < 0 || pipe (childPipe) < 0) return 0;

		int pid = fork();
		if (pid < 0) return 0;
		else if (pid == 0) {
			// child

			close(childPipe[WRITE]);
			close(parentPipe[READ]);

			//int x;
			//read(childPipe[READ], &x, sizeof(int));
			printf("[CHILD] %d\n", initNum);
			initNum /= 2;
			printf("[CHILD2] %d\n", initNum); 
			write(parentPipe[WRITE], &initNum, sizeof(int));

			close(childPipe[READ]);
			close(parentPipe[WRITE]);
			//exit(0);
			
			
		} //else {
			// parent

			close(childPipe[READ]);
			close(parentPipe[WRITE]);

			printf("[PARENT] %d\n", initNum);
			write(childPipe[WRITE], &initNum, sizeof(int));
			
			wait(0);
			read(parentPipe[READ], &initNum, sizeof(int));

			close(childPipe[WRITE]);
			close(parentPipe[READ]);
		//}
	}	

	return 0;
}
