//
// Using named pipe (FIFO) - Read from a FIFO
//

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
	char* myfifo = "./myfifo";
	int fd = open(myfifo, O_RDONLY);
	char msg[100];
	read(fd, msg, 100);
	printf("got message: %s\n", msg);
	close(fd);

	return 0;
}
