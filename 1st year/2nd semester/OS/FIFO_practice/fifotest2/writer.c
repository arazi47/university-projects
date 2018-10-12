#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
	char *myfifo = "./myfifo";

	int res = mkfifo(myfifo, 0666);
	int fd = open(myfifo, O_WRONLY);

	printf("reader connected; give message: ");
	char message[100];
	fgets(message, 100, stdin);
	write(fd, message, sizeof(message));

	close(fd);
	unlink(myfifo);

	return 0;
}
