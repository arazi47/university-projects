//
// Using named pipe (FIFO) - Create and write to a FIFO
//

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	char* myfifo = "./myfifo";
	mkfifo(myfifo, 0666);
	int fd = open(myfifo, O_WRONLY);
	printf("reader connected. give message: ");
	char msg[100];
	fgets(msg, 100, stdin);
	write(fd, msg, sizeof(msg));
	close(fd);
	unlink(myfifo);

	return 0;
}
