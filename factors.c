#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "main.h"

#define MAX_LINE_LENGTH 100

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    clock_t start_time;
    unsigned long number; /* Declare the variable here */

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    start_time = clock();

    while (fgets(line, sizeof(line), file) != NULL) {
        /* Remove trailing newline characters */
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        number = strtoul(line, NULL, 10); /* Assign the value here */
        if (number == 0) {
            fprintf(stderr, "Invalid number in the file: %s\n", line);
            continue;
        }

        factorize(number);

        /* Check for time limit */
        if (isTimeLimitExceeded(start_time, 5)) {
            printf("Time limit exceeded\n");
            break;
        }
    }

    fclose(file);
    return EXIT_SUCCESS;
}

/**
 * factorize - Factorize a number into two smaller numbers.
 * @n: The number to factorize.
 */
void factorize(unsigned long n) {
    unsigned long p = 2;

    while (p <= n / 2) {
        if (n % p == 0) {
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
int isTimeLimitExceeded(clock_t start_time, int time_limit) {
    return (clock() - start_time) >= (time_limit * CLOCKS_PER_SEC);
}

