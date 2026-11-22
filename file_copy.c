#include <stdio.h>

int main(void)
{
    FILE *sourceFile;
    FILE *destinationFile;
    char sourceName[200], destinationName[200];
    int character;

    printf("Enter source file name: ");
    scanf("%199s", sourceName);
    printf("Enter destination file name: ");
    scanf("%199s", destinationName);

    sourceFile = fopen(sourceName, "rb");
    if (sourceFile == NULL) {
        printf("Unable to open source file.\n");
        return 1;
    }

    destinationFile = fopen(destinationName, "wb");
    if (destinationFile == NULL) {
        printf("Unable to create destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    while ((character = fgetc(sourceFile)) != EOF) {
        fputc(character, destinationFile);
    }

    fclose(sourceFile);
    fclose(destinationFile);

    printf("File copied successfully.\n");
    return 0;
}
