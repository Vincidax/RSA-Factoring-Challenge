#ifndef MAIN_H
#define MAIN_H

#include <time.h>

#define MAX_LINE_LENGTH 100

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[]);

/**
 * processFile - Process the input file and factorize numbers.
 * @filename: The name of the input file.
 */
void processFile(const char *filename);

/**
 * factorize - Factorize a number into two smaller numbers.
 * @n: The number to factorize.
 */
void factorize(unsigned long n);

/**
 * removeNewline - Remove trailing newline characters from a string.
 * @str: The string to modify.
 */
void removeNewline(char *str);

/**
 * isTimeLimitExceeded - Check if the time limit is exceeded.
 * @start_time: The start time of execution.
 * @time_limit: The time limit in seconds.
 *
 * Return: 1 if the time limit is exceeded, 0 otherwise.
 */
int isTimeLimitExceeded(clock_t start_time, int time_limit);

#endif /* MAIN_H */

