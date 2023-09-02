#!/bin/bash

# Check for the correct number of arguments
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <input_file>"
    exit 1
fi

# Define the input file and temporary file
input_file="$1"
temp_file="/tmp/factors_temp_file.txt"

# Run factors.py and save its output to a temporary file
./factors "$input_file" > "$temp_file"

# Capture the timing information using the 'time' command
timing_info=$( { time ./factors "$input_file" > /dev/null; } 2>&1 )

# Print the factorization results from the temporary file
cat "$temp_file"

# Print a newline
echo ""

# Print the timing information
echo "$timing_info"
