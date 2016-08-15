#ifndef __ALLOX_GUARD
#define __ALLOX_GUARD

#define PAGE_SHIFT      12
#define HPAGE_SHIFT     21
#define PAGE_SIZE       (1<<PAGE_SHIFT)
#define HPAGE_SIZE      (1<<HPAGE_SHIFT)
#define PAGES_PER_HPAGE (HPAGE_SIZE/PAGE_SIZE)

/* Number of huge page-blocks to allocate. */
#define HPAGES 42
#define TOTAL_PAGES (HPAGES * PAGES_PER_HPAGE)

/* Wait for input. */
static inline void block(void)
{
	puts("<hit ret>");
	getchar();
}

/* Summarise allocation. */
static inline void summarise(void)
{
	printf("Allocated %d pages = %d huge pages = %dMiB (%dKiB).\n",
		TOTAL_PAGES,
		HPAGES,
		(TOTAL_PAGES * PAGE_SIZE)/(1024 * 1024),
		(TOTAL_PAGES * PAGE_SIZE)/1024);
}

#endif
