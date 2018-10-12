#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int x;
	//printf("give x: ");
	//scanf("%d", &x);

	int fd[2];
	int pipeRes = pipe(fd);

	if (pipeRes == -1)
		return 0;

	int forkRes = fork();

	if (forkRes == -1) {
		return -1;
	} else if (forkRes == 0) {
		// child
		int y;
		scanf("%d", &y);
		close(fd[0]);

		y += 1;
		write(fd[1], &y, sizeof(int));
		close(fd[1]);
		
	} else {
		// parent
		close(fd[1]);
		read(fd[0], &x, sizeof(int));
		close(fd[0]);
		int status;
		wait(&status);
		printf("x is now %d\n", x);
	}

	return 0;
}
