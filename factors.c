#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "main.h"

#define MAX_LINE_LENGTH 100

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return (EXIT_FAILURE);
    }

    processFile(argv[1]);

    return (EXIT_SUCCESS);
}

/**
 * processFile - Process a file containing natural numbers to factor.
 * @filename: The name of the file to process.
 */
void processFile(const char *filename)
{
    /* Declare the variable at the beginning of the function */
    clock_t start_time;
    char line[MAX_LINE_LENGTH];
    unsigned long number;
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    /* Initialize the variable */
    start_time = clock();
    while (fgets(line, sizeof(line), file) != NULL)
    {
        removeNewline(line);

        number = getNumberFromString(line);
        if (number == 0)
        {
            fprintf(stderr, "Invalid number in the file: %s\n", line);
            continue;
        }

        factorize(number);

        if (isTimeLimitExceeded(start_time, 5))
        {
            printf("Time limit exceeded\n");
            break;
        }
    }

    fclose(file);
}

/**
 * removeNewline - Remove trailing newline characters from a string.
 * @str: The string to modify.
 */
void removeNewline(char *str)
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}

/**
 * getNumberFromString - Convert a string to an unsigned long integer.
 * @str: The string to convert.
 *
 * Return: The converted number.
 */
unsigned long getNumberFromString(const char *str)
{
    return strtoul(str, NULL, 10);
}

/**
 * factorize - Factorize a number into two smaller numbers.
 * @n: The number to factorize.
 */
void factorize(unsigned long n)
{
    unsigned long p = 2;

    while (p <= n / 2)
    {
        if (n % p == 0)
        {
            printf("%lu=%lu*%lu\n", n, p, n / p);
            return;
        }
        p++;
    }

    printf("%lu=%lu*1\n", n, n);
}

/**
 * isTimeLimitExceeded - Check if the time limit is exceeded.
 * @start_time: The start time of execution.
 * @time_limit: The time limit in seconds.
 *
 * Return: 1 if the time limit is exceeded, 0 otherwise.
 */
int isTimeLimitExceeded(clock_t start_time, int time_limit)
{
    return ((clock() - start_time) >= (time_limit * CLOCKS_PER_SEC));
}

