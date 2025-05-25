#include <stdio.h>

// For exit, EXIT_FAILURE
#include <stdlib.h>

int cp(char *fileSrcPath, char *fileDstPath)
{
    FILE *srcFile, *dstFile;

    srcFile = fopen(fileSrcPath, "rb");
    dstFile = fopen(fileDstPath, "wb");

    // Check if the source file was opened successfully
    if (srcFile == NULL || dstFile == NULL)
    {
        // If either file could not be opened, print an error message
        fprintf(stderr, "Error opening files: %s or %s\n", fileSrcPath, fileDstPath);
        return 1;
    }

    char buffer[1024];
    size_t bytesRead;
    // Read from the source file and write to the destination file
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), srcFile)) > 0)
    {
        fwrite(buffer, 1, bytesRead, dstFile);
    }
    // Close both files
    fclose(srcFile);
    fclose(dstFile);

    printf("File copied successfully from %s to %s\n", fileSrcPath, fileDstPath);
    fflush(stdout);

    // Return a success message
    return 0;
}

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
