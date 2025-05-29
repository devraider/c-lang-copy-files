
# Makefile for cp utility
CC=gcc
LIBS=libs
CFLAGS=-Wall -Wextra -pedantic -std=c99

# Targets
all: cp

# Build target for cp
cp: 
	$(CC) $(CFLAGS) src/main.c -o cp

# Remove target binary and object files
remove:
	rm -f cp

# Clean binary and libraries
clean:
	rm -rf cp libs src/cp

test:
	@echo "Running tests..."
	$(CC) $(CFLAGS) tests/test_cp.c -o test_cp
	./test_cp
	@echo "Tests completed."

# Install libraries and dependencies
install-all:
	bash resolve_deps.sh

