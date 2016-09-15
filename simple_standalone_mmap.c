#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

/* 10MiB */
#define SIZE (10 << 20)

int main(void)
{
	unsigned char *ptr = mmap(NULL, SIZE, PROT_READ | PROT_WRITE,
				MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (ptr == MAP_FAILED) {
		perror("mmap");
		exit(1);
	}

	puts("<hit ret>");
	getchar();

	ptr[0] = 'x';
	ptr[SIZE - 1] = 'y';

	puts("<hit ret>");
	getchar();

	memset(ptr, 'x', SIZE);

	puts("<hit ret>");
	getchar();

	return EXIT_SUCCESS;
}
