#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

#include "allox.h"

static void fatal_perror(void)
{
	perror("simple_single_mmap");
	exit(1);
}

int main(int argc, char *argv[])
{
	int i;
	unsigned char *ptr;

	parse_args(argc, argv);

	ptr = mmap(NULL, SIZE, PROT_READ | PROT_WRITE,
		MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (ptr == MAP_FAILED)
		fatal_perror();

	/* Touch each 4KiB page. */
	for (i = 0; i < TOTAL_PAGES; i++)
		ptr[i * PAGE_SIZE] = 'x';

	summarise(ptr);
	block();

	if (munmap(ptr, SIZE))
		fatal_perror();

	return EXIT_SUCCESS;
}
