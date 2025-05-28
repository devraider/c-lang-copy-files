#include <stdio.h>
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
