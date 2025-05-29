# Poject

A command-line utility written in C that mimics the core functionality of the standard GNU `cp` (copy) command. It allows users to copy files from one location to another within the filesystem.

## Motivation

he primary motivation behind this project is to strengthen C programming skills by building a practical, real-world utility. It provides hands-on experience with:

- **File I/O operations**: Reading from and writing to files using fopen, fread, fwrite, and fclose.
- **Command-line argument parsing**: Handling argc and argv for user input.
- **Error handling**: Robustly managing file opening failures, read/write errors, and incorrect usage.
- **Project structuring**: Organizing C source code and tests into a maintainable directory tree.
- **Build systems**: Using Makefiles to automate compilation and testing.

## Tech stack

- **Language**: C (C99 standard)
- **Compiler**: `gcc`
- **Build System**: Make
- **Unit Testing Framework**: Unity

## Features

- Copies a single file from a source path to a destination path.
- Copies files in chunks for efficient performance, minimizing system calls.
- Reports errors if source file cannot be opened (e.g., does not exist, permission denied).
- Unit tests for core functionality using the Unity framework.

## Installation

1. Clone the repository:

```bash
git clone git@github.com:devraider/c-lang-copy-files.git
cd c-lang-copy-files
```

2. Resolve Dependencies:

```bash
make install-all
```

3. Build the `cp` executable

```bash
make cp
```

4. Run

```bash
./cp samples/sample.txt samples/dest.txt
```

## Testing

The project includes a suite of unit tests to ensure the cp function behaves as expected.

```bash
make test
```
