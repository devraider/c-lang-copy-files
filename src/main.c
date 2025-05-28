#include <stdio.h>
#include <stdlib.h>
#include "cp.c"

int main(int argc, char *argv[])
{

    // Handle error states for the number of arguments.
    // We expect exactly 2 arguments: source file and destination file.
    // argc should be 3 (program name + 2 arguments).
    if (argc > 3 || argc < 3)
    {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *fileSrc = argv[1];
    char *fileDst = argv[2];

    // Call the cp function
    cp(fileSrc, fileDst);

    return 0;
}
