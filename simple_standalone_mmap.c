#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

/* 10MiB */
#define SIZE (10<<20)

int main(void)
{
	void *ptr = mmap(NULL, SIZE, PROT_READ | PROT_WRITE,
		MAP_PRIVATE | MAP_ANONYMOUS | MAP_POPULATE, -1, 0);
	if (ptr == MAP_FAILED) {
		perror("mmap");
		exit(1);
	}

	puts("<hit ret>");
	getchar();

	return EXIT_SUCCESS;
}
