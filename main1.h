#ifndef MAIN1_H
#define MAIN1_H

/**
 * pollard_rho - Implement Pollard's Rho algorithm for factorization
 * @n: The number to be factorized
 *
 * This function uses Pollard's Rho algorithm to find a non-trivial factor
 * of the given number.
 *
 * Return: A non-trivial factor of n, or 1 if none is found
 */
int pollard_rho(int n);

/**
 * is_prime - Check if a number is prime
 * @num: The number to be checked
 *
 * This function checks if a given number is prime.
 *
 * Return: 1 if num is prime, 0 otherwise
 */
int is_prime(int num);

/**
 * read_number - Read an integer from a file
 * @file_path: The path to the file containing the integer
 *
 * This function reads an integer from a file specified by file_path.
 *
 * Return: The integer read from the file, or -1 on error
 */
int read_number(const char *file_path);

/**
 * find_prime_factors - Find the prime factors of a number
 * @number: The number to be factorized
 * @prime_factors: A pointer to an array to store the prime factors
 * @count: A pointer to an integer to store the count of prime factors
 *
 * This function finds the prime factors of a given number and returns them
 * in the prime_factors array. The count of prime factors is stored in the
 * count variable.
 */
void find_prime_factors(int number, int **prime_factors, int *count);

#endif /* MAIN1_H */
