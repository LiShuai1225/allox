#ifndef __ALLOX_GUARD
#define __ALLOX_GUARD

#define PAGE_SIZE       (4 * 1024)
#define HPAGE_SIZE      (2 * 1024 * 1024)
#define PAGES_PER_HPAGE (HPAGE_SIZE/PAGE_SIZE)

/* Wait for input. */
static inline void block(void)
{
	puts("<hit ret>");
	getchar();
}

#endif
