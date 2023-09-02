#ifndef MAIN_H
#define MAIN_H

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
