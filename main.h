#ifndef MAIN_H
#define MAIN_H

/**
 * processFile - Process a file containing natural numbers to factor.
 * @filename: The name of the file to process.
 */
void processFile(const char *filename);

/**
 * removeNewline - Remove trailing newline characters from a string.
 * @str: The string to modify.
 */
void removeNewline(char *str);

/**
 * getNumberFromString - Convert a string to an unsigned long integer.
 * @str: The string to convert.
 *
 * Return: The converted number.
 */
unsigned long getNumberFromString(const char *str);

/**
 * factorize - Factorize a number into two smaller numbers.
 * @n: The number to factorize.
 */
void factorize(unsigned long n);

/**
 * isTimeLimitExceeded - Check if the time limit is exceeded.
 * @start_time: The start time of execution.
 * @time_limit: The time limit in seconds.
 *
 * Return: 1 if the time limit is exceeded, 0 otherwise.
 */
int isTimeLimitExceeded(clock_t start_time, int time_limit);

#endif /* MAIN_H */

