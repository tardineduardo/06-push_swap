#!/bin/bash

# Check if a number is provided as an argument
if [ -z "$1" ]; then
    echo "Usage: $0 <number of random numbers to generate>"
    exit 1
fi

# Generate the specified number of random numbers
args=$(shuf -i 1-1000 -n "$1" | tr '\n' ' ')
# Print the sequence of numbers
echo "Generated sequence: $args"
./push_swap $args | ./checker_linux $args
echo ""

# Generate the specified number of random numbers
args=$(shuf -i 1-1000 -n "$1" | tr '\n' ' ')
# Print the sequence of numbers
echo "Generated sequence: $args"
./push_swap $args | ./checker_linux $args
echo ""

# Generate the specified number of random numbers
args=$(shuf -i 1-1000 -n "$1" | tr '\n' ' ')
# Print the sequence of numbers
echo "Generated sequence: $args"
./push_swap $args | ./checker_linux $args
echo ""

# Generate the specified number of random numbers
args=$(shuf -i 1-1000 -n "$1" | tr '\n' ' ')
# Print the sequence of numbers
echo "Generated sequence: $args"
./push_swap $args | ./checker_linux $args
echo ""

# Generate the specified number of random numbers
args=$(shuf -i 1-1000 -n "$1" | tr '\n' ' ')
# Print the sequence of numbers
echo "Generated sequence: $args"
./push_swap $args | ./checker_linux $args
echo ""