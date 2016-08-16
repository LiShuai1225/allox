#ifndef __ALLOX_GUARD
#define __ALLOX_GUARD

#define PAGE_SHIFT      12
#define HPAGE_SHIFT     21
#define PAGE_SIZE       (1UL<<PAGE_SHIFT)
#define HPAGE_SIZE      (1UL<<HPAGE_SHIFT)
#define PAGE_MASK       (~(PAGE_SIZE-1UL))
#define HPAGE_MASK      (~(HPAGE_SIZE-1UL))
#define PAGES_PER_HPAGE (HPAGE_SIZE/PAGE_SIZE)

/* Number of huge page-blocks to allocate. */
#define HPAGES 42UL
#define TOTAL_PAGES (HPAGES * PAGES_PER_HPAGE)

/* Wait for input. */
static inline void block(void)
{
	puts("<hit ret>");
	getchar();
}

/* Summarise allocation. */
static inline void summarise(void *ptr)
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

#endif
