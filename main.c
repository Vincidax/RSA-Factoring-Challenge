#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "main1.h"

void print_result(int number, int *prime_factors, int count);

int main(int argc, char *argv[])
{
    char *file_path;
    int number;
    int *prime_factors = NULL;
    int count = 0;
    double elapsed_time;
    clock_t start_time; /* Move the declaration here */

    if (argc != 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    file_path = argv[1];
    number = read_number(file_path);

    if (number == -1)
    {
        return 1;
    }

    start_time = clock(); /* Initialize the variable here */
    find_prime_factors(number, &prime_factors, &count);

    print_result(number, prime_factors, count);
    free(prime_factors);

    elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;
    if (elapsed_time > 5)
    {
        printf("Time limit exceeded\n");
        return 1;
    }

    return 0;
}

void print_result(int number, int *prime_factors, int count)
{
    int i; /* Declare i at the beginning of the function */

    if (count == 1)
    {
        printf("%d is prime.\n", number);
    }
    else
    {
        printf("%d=", number);
        for (i = 0; i < count - 1; i++)
        {
            printf("%d*", prime_factors[i]);
        }
        printf("%d\n", prime_factors[count - 1]);
    }
}

