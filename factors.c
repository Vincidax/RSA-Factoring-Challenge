#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "main.h"

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (1);
	}

	processFile(argv[1]);

	return (0);
}

/**
 * processFile - Process the input file and factorize numbers.
 * @filename: The name of the input file.
 */
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
		exit(1);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		removeNewline(line);

		number = strtoul(line, NULL, 10); /* Convert string to unsigned long */
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

/**
 * factorize - Factorize a number into two smaller numbers.
 * @n: The number to factorize.
 */
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

/**
 * removeNewline - Remove trailing newline characters from a string.
 * @str: The string to modify.
 */
void removeNewline(char *str)
{
	size_t len = strlen(str);

	if (len > 0 && str[len - 1] == '\n')
	{
		str[len - 1] = '\0';
	}
}

/**
 * isTimeLimitExceeded - Check if the time limit is exceeded.
 * @start_time: The start time of execution.
 * @time_limit: The time limit in seconds.
 *
 * Return: 1 if the time limit is exceeded, 0 otherwise.
 */
int isTimeLimitExceeded(clock_t start_time, int time_limit)
{
	return ((clock() - start_time) >= (time_limit * CLOCKS_PER_SEC));
}

