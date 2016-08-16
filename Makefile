# Source shared between all targets.
shared=helpers.c

# Determine targets.
# Adapted from http://stackoverflow.com/a/2706067/6380063 with thanks.
srcs=$(wildcard *.c)
headers=$(wildcard *.h)
target_srcs=$(filter-out $(shared), $(srcs))
targets=$(patsubst %.c,%,$(target_srcs))

CFLAGS+=-g -pedantic -Wall -Werror

all: $(targets)

%: %.c $(shared) $(headers)
	$(CC) $(CFLAGS) -o $@ $(filter-out %.h, $^)
	valgrind --leak-check=full $(PWD)/$@ </dev/null

clean:
	rm -f $(targets)

.phony: all clean
