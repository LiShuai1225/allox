#ifndef __ALLOX_GUARD
#define __ALLOX_GUARD

#define PAGE_SHIFT      12
#define HPAGE_SHIFT     21
#define PAGE_SIZE       (1UL<<PAGE_SHIFT)
#define HPAGE_SIZE      (1UL<<HPAGE_SHIFT)
#define PAGE_MASK       (~(PAGE_SIZE-1UL))
#define HPAGE_MASK      (~(HPAGE_SIZE-1UL))
#define PAGES_PER_HPAGE (HPAGE_SIZE/PAGE_SIZE)

#define HPAGES      42UL
#define TOTAL_PAGES (HPAGES * PAGES_PER_HPAGE)
#define SIZE        (HPAGES * HPAGE_SIZE)

/* helpers.c */
void block(void);
void summarise(void *ptr);
void parse_args(int argc, char *argv[]);
void fatal_perror(const char *msg);

#endif
