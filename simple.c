#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PAGE_SIZE       (4 * 1024)
#define HPAGE_SIZE      (2 * 1024 * 1024)
#define PAGES_PER_HPAGE (HPAGE_SIZE/PAGE_SIZE)

/* Number of huge page-blocks to allocate. */
#define HPAGES 42
#define TOTAL_PAGES (HPAGES * PAGES_PER_HPAGE)

/* Wait for input. */
static void block(void)
{
	puts("<hit ret>");
	getchar();
}

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

	printf("Allocated %d pages = %dMiB.\n", TOTAL_PAGES,
		(TOTAL_PAGES * PAGE_SIZE)/(1024*1024));
	block();

	/* Not strictly necessary, but good habit to free regardless. */
	for (i = 0; i < TOTAL_PAGES; i++)
		free(ptrs[i]);

	return EXIT_SUCCESS;
}
