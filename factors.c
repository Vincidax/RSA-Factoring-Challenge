#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "main.h"

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

void processFile(const char *filename)
{
    clock_t start_time;
    FILE *file;
    char line[MAX_LINE_LENGTH];
    unsigned long number;

    start_time = clock();
    file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

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

void removeNewline(char *str)
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}

unsigned long getNumberFromString(const char *str)
{
    return strtoul(str, NULL, 10);
}

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

int isTimeLimitExceeded(clock_t start_time, int time_limit)
{
    return ((clock() - start_time) >= (time_limit * CLOCKS_PER_SEC));
}

