# Adapted from http://stackoverflow.com/a/2706067/6380063 with thanks.
srcs=$(wildcard *.c)
names=$(patsubst %.c,%,$(srcs))

all: $(names)

%: %.c
	$(CC) $(CFLAGS) -g -pedantic -Wall -Werror -o $@ $<
	valgrind $(PWD)/$@ </dev/null

clean:
	rm -f $(names)

.phony: all clean
