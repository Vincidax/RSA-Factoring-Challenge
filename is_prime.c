#include <math.h>
#include "main1.h"

/**
 * is_prime - Check if a number is prime
 * @num: The number to be checked
 *
 * This function checks if a given number is prime.
 *
 * Return: 1 if num is prime, 0 otherwise
 */
int is_prime(int num)
{
    int i;

    if (num < 2)
    {
        return 0;
    }

    for (i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }

    return 1;
}
