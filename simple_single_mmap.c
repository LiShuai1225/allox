#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

#include "allox.h"

int main(void)
{
	int i;
	unsigned char *ptr = mmap(NULL, HPAGES * HPAGE_SIZE, PROT_READ | PROT_WRITE,
				MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (ptr == MAP_FAILED) {
		perror("simple_single_mmap");
		exit(1);
	}

	/* Touch each 4KiB page. */
	for (i = 0; i < TOTAL_PAGES; i++)
		ptr[i * PAGE_SIZE] = 'x';

	summarise(ptr);
	block();

	return EXIT_SUCCESS;
}
