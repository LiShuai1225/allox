#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

#include "allox.h"

int main(int argc, char *argv[])
{
	int i;
	unsigned char *ptrs[TOTAL_PAGES];

	parse_args(argc, argv);

	for (i = 0; i < TOTAL_PAGES; i++) {
		ptrs[i] = malloc(PAGE_SIZE);
		if (ptrs[i] == NULL) {
			perror("simple_multi_malloc");
			exit(1);
		}

		/* Touch page. */
		ptrs[i][0] = 'x';
	}

	summarise(NULL);
	block();

	/* Not strictly necessary, but good habit to free regardless. */
	for (i = 0; i < TOTAL_PAGES; i++)
		free(ptrs[i]);

	return EXIT_SUCCESS;
}
