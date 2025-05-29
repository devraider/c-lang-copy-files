#include <stdio.h>
#include <stdlib.h>

int cp(char *fileSrcPath, char *fileDstPath)
{
    FILE *srcFile, *dstFile;

    srcFile = fopen(fileSrcPath, "rb");

    // Check if the source file was opened successfully
    if (srcFile == NULL)
    {
        fprintf(stderr, "Error opening source file: %s\n", fileSrcPath);
        fclose(srcFile);

        return 1;
    }

    dstFile = fopen(fileDstPath, "wb");
    if (dstFile == NULL)
    {
        // If either file could not be opened, print an error message
        fprintf(stderr, "Error opening destination file: %s\n", fileDstPath);
        fclose(srcFile);
        fclose(dstFile);

        return 1;
    }
    char buffer[1024];
    size_t bytesRead;

    // Read from the source file and write to the destination file
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), srcFile)) > 0)
    {
        fwrite(buffer, 1, bytesRead, dstFile);
    }
    fclose(srcFile);
    fclose(dstFile);

    printf("File copied successfully from %s to %s\n", fileSrcPath, fileDstPath);
    fflush(stdout);

    return 0;
}
