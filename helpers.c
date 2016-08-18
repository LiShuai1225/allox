#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "allox.h"

static int do_suspend;

/* Wait for input. */
void block(void)
{
	if (do_suspend)
		pause();
	else {
		puts("<hit ret>");
		getchar();
	}
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

void parse_args(int argc, char *argv[])
{
	char *flag;

	if (argc < 2)
		return;

	flag = argv[1];

	if (strcmp(flag, "--suspend") == 0)
		do_suspend = 1;
}

void fatal_perror(const char *msg)
{
	perror(msg);
	exit(1);
}
