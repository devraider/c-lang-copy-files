#include <stdio.h>

// For exit, EXIT_FAILURE
#include <stdlib.h>

char *cp()
{

    printf("Runnig cp....\n");
    return "Done";
}

int main(int argc, char *argv[])
{

    // Handle error
    if (argc > 3 || argc < 3)
    {
        // Handling an error state.
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *fileSrc = argv[1];
    char *fileDst = argv[2];

    printf("Source file {%s} to destindation {%s} {%i}", fileSrc, fileDst, argc);

    return 0;
}