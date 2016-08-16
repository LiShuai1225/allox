#include <stdio.h>

#include "allox.h"

/* Wait for input. */
void block(void)
{
	puts("<hit ret>");
	getchar();
}

/* Summarise allocation. */
void summarise(void *ptr)
{
	unsigned long addr;

	if (ptr) {
		addr = (unsigned long)ptr&PAGE_MASK;
		printf("Address = %016lx (lower %d bits = %06lx)\n", addr, HPAGE_SHIFT, addr&(~HPAGE_MASK));
	}

	printf("Allocated %ld pages = %ld huge pages = %ldMiB (%ldKiB).\n",
		TOTAL_PAGES,
		HPAGES,
		(TOTAL_PAGES * PAGE_SIZE)/(1024 * 1024),
		(TOTAL_PAGES * PAGE_SIZE)/1024);
}
