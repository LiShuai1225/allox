#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

#include "allox.h"

int main(int argc, char *argv[])
{
	unsigned char *ptr;

	parse_args(argc, argv);

	ptr = mmap(NULL, SIZE, PROT_READ | PROT_WRITE,
		MAP_PRIVATE | MAP_ANONYMOUS | MAP_POPULATE, -1, 0);
	if (ptr == MAP_FAILED)
		fatal_perror("simple_single_mmap: mmap");

	summarise(ptr);
	block();

	if (munmap(ptr, SIZE))
		fatal_perror("simple_single_mmap: munmap");

	return EXIT_SUCCESS;
}
