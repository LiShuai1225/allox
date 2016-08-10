#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

#include "allox.h"

int main(void)
{
	int i;
	unsigned char *ptr = malloc(HPAGES * HPAGE_SIZE);

	/* Touch each 4KiB page. */
	for (i = 0; i < TOTAL_PAGES; i++) {
		ptr[i * PAGE_SIZE] = 'x';
	}

	summarise();
	block();

	/* Not strictly necessary, but good habit to free regardless. */
	free(ptr);

	return EXIT_SUCCESS;
}
