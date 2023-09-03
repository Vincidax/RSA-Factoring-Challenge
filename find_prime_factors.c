#include <stdio.h>
#include <stdlib.h>
#include "main1.h"

void find_prime_factors(int number, int **prime_factors, int *count)
{
    int *factors = NULL; /* Array to store prime factors */
    int factors_count = 0; /* Count of prime factors */
    int divisor = 2; /* Start with the smallest prime number */

    while (number > 1)
    {
        if (number % divisor == 0)
        {
            /* Divisor is a prime factor, add it to the factors array */
            factors_count++;
            factors = (int *)realloc(factors, factors_count * sizeof(int));
            factors[factors_count - 1] = divisor;

            /* Reduce the number by dividing it by the divisor */
            number /= divisor;
        }
        else
        {
            /* Increment the divisor */
            divisor++;
        }
    }

    /* Set the output values */
    *prime_factors = factors;
    *count = factors_count;
}

