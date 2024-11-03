#!/bin/bash

# Check if a number is provided as an argument
if [ -z "$1" ]; then
    echo "Usage: $0 <number of random numbers to generate>"
    exit 1
fi

# Generate the specified number of random numbers
argc=$(shuf -i 1-1000 -n "$1" | tr '\n' ' ')

# Print the sequence of numbers
echo "Generated sequence: $argc"

# Run the program with a timeout of 5 seconds
timeout 5 ./push_swap $argc

# Check if the program exited due to a timeout or segmentation fault
if [ $? -eq 124 ]; then
    echo "Process timed out (potential infinite loop)."
elif [ $? -eq 139 ]; then
    echo "Segmentation fault detected."
fi