#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

#include "allox.h"

/* Number of huge page-blocks to allocate. */
#define HPAGES 42
#define TOTAL_PAGES (HPAGES * PAGES_PER_HPAGE)

int main(void)
{
	int i;
	unsigned char *ptr = malloc(HPAGES * HPAGE_SIZE);

	/* Touch each 4KiB page. */
	for (i = 0; i < TOTAL_PAGES; i++) {
		ptr[i * PAGE_SIZE] = 'x';
	}

	printf("Allocated %d pages = %d huge pages = %dMiB (%dKiB).\n",
		TOTAL_PAGES,
		HPAGES,
		(TOTAL_PAGES * PAGE_SIZE)/(1024 * 1024),
		(TOTAL_PAGES * PAGE_SIZE)/1024);
	block();

	/* Not strictly necessary, but good habit to free regardless. */
	free(ptr);

	return EXIT_SUCCESS;
}
