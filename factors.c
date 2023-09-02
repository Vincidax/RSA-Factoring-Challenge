#include <stdio.h>
#include <stdlib.h>

/**
 * factorize - Factorizes an integer and prints the result.
 * @number: The integer to factorize.
 */
void factorize(int number)
{
	int p, q;

	for (p = 2; p <= number; ++p)
	{
		if (number % p == 0)
		{
			q = number / p;
			printf("%d = %d * %d\n", number, p, q);
			return;
		}
	}
}

/**
 * main - Reads integers from a file and attempts to factorize them.
 * @argc: The number of command-line arguments.
 * @argv: The array of command-line arguments.
 * Return: 0 on success, non-zero on failure.
 */
int main(int argc, char *argv[])
{
	char *file_path;
	FILE *file;
	char line[256]; /* Assuming lines in the file are not longer than 255 chars */

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (1);
	}
	file_path = argv[1];
	file = fopen(file_path, "r");

	if (file == NULL)
	{
		fprintf(stderr, "File '%s' not found.\n", file_path);
		return (1);
	}

	while (fgets(line, sizeof(line), file))
	{
		int num = atoi(line);

		if (num <= 1)
		{
			fprintf(stderr, "Invalid number in the file: %d\n", num);
			continue;
		}
		factorize(num);
	}
	fclose(file);
	return (0);
}
