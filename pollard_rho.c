#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "main1.h"

/**
 * f - Calculate the next value in the sequence
 * @x: The current value
 * @n: The number to be factorized
 *
 * This function calculates the next value in the sequence used by Pollard's Rho
 * algorithm.
 *
 * Return: The next value in the sequence
 */
static int f(int x, int n)
{
    return ((x * x + 1) % n);
}

/**
 * pollard_rho - Implement Pollard's Rho algorithm for factorization
 * @n: The number to be factorized
 *
 * This function uses Pollard's Rho algorithm to find a non-trivial factor
 * of the given number.
 *
 * Return: A non-trivial factor of n, or 1 if none is found
 */
int pollard_rho(int n)
{
    int x = 2, y = 2, d = 1;

    while (d == 1)
    {
        x = f(x, n);
        y = f(f(y, n), n);
        d = abs(x - y);
        d = is_prime(d) ? d : 1;
    }

    return d;
}

