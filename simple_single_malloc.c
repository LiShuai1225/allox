#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

#include "allox.h"

int main(void)
{
	int i;
	unsigned char *ptr = malloc(HPAGES * HPAGE_SIZE);

	if (ptr == NULL) {
		perror("simple_single_malloc");
		exit(1);
	}

	/* Touch each 4KiB page. */
	for (i = 0; i < TOTAL_PAGES; i++)
		ptr[i * PAGE_SIZE] = 'x';

	summarise(ptr);
	block();

	/* Not strictly necessary, but good habit to free regardless. */
	free(ptr);

	return EXIT_SUCCESS;
}
