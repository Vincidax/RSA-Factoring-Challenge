#!/usr/bin/python3

import time
import sys


def factorize(number):
    """
    Factorize a number into two smaller numbers.
    """
    for p in range(2, number + 1):
        if number % p == 0:
            q = number // p
            return p, q
    return None, None


def main():
    # Check if the correct number of command-line arguments is provided
    if len(sys.argv) != 2:
        # Print the correct usage of the program
        print("Usage: factors <file>")
        # Exit the program if the correct arguments are not provided
        return

    # Get the file path from the command-line argument
    file_path = sys.argv[1]

    # Start timing
    start_time = time.time()

    try:
        # Open the file in read mode
        with open(file_path, 'r') as file:
            numbers = file.readlines()

        # Iterate through each number in the list
        for number in numbers:
            num = int(number.strip())
            p, q = factorize(num)

            if p is not None and q is not None:
                # Print the factorization in the required format
                print(f"{num}={p}*{q}")
            else:
                # If unable to factorize, print a message
                print(f"Unable to factorize {num}")

            if time.time() - start_time > 5:
                print("Time limit exceeded")
                exit()

    except FileNotFoundError:
        print(f"File '{file_path}' not found.")


if __name__ == '__main__':
    main()
