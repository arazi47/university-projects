#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
	char *myfifo = "./myfifo";

	int fd = open(myfifo, O_RDONLY);

	char message[100];
	read(fd, message, 100);

	printf("got message: %s\n", message);

	close(fd);

	return 0;
}
