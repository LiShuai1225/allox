#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "allox.h"

/* Number of huge page-blocks to allocate. */
#define HPAGES 42
#define TOTAL_PAGES (HPAGES * PAGES_PER_HPAGE)

static void say_pid(void)
{
	printf("PID = %d\n", getpid());
}

int main(void)
{
	int i;
	unsigned char *ptrs[TOTAL_PAGES];

	say_pid();

	for (i = 0; i < TOTAL_PAGES; i++) {
		ptrs[i] = malloc(PAGE_SIZE);
		/* Touch page. */
		ptrs[i][0] = 'x';
	}

	printf("Allocated %d pages = %d huge pages = %dMiB (%dKiB).\n",
		TOTAL_PAGES,
		TOTAL_PAGES/PAGES_PER_HPAGE,
		(TOTAL_PAGES * PAGE_SIZE)/(1024 * 1024),
		(TOTAL_PAGES * PAGE_SIZE)/1024);
	block();

	/* Not strictly necessary, but good habit to free regardless. */
	for (i = 0; i < TOTAL_PAGES; i++)
		free(ptrs[i]);

	return EXIT_SUCCESS;
}
