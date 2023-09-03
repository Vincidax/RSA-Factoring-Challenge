#include <stdio.h>
#include <stdlib.h>
#include "main1.h"

/**
 * read_number - Read an integer from a file
 * @file_path: The path to the file containing the integer
 *
 * This function reads an integer from a file specified by file_path.
 *
 * Return: The integer read from the file, or -1 on error
 */
int read_number(const char *file_path)
{
    FILE *file = fopen(file_path, "r");
    int number;

    if (file == NULL)
    {
        printf("File '%s' not found.\n", file_path);
        return -1;
    }

    if (fscanf(file, "%d", &number) != 1)
    {
        printf("Invalid input in the file.\n");
        fclose(file);
        return -1;
    }

    fclose(file);
    return number;
}
