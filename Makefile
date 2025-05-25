

CC=gcc
LIBS=libs

CFLAGS=-Wall -Wextra -pedantic -std=c99

all: cp


cp: 
	$(CC) $(CFLAGS) cp.c -o cp

clean:
	rm -f cp


remove:
	rm -rf cp libs src/cp


install-all:
	bash resolve_deps.sh

