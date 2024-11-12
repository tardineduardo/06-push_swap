#!/bin/bash

# Number of iterations and the count of numbers to generate
iterations=$1  # First argument: number of iterations
num_count=$2   # Second argument: number of random numbers to generate in each iteration

# ANSI color codes
GREEN="\033[32m"
RED="\033[31m"
RESET="\033[0m"

# Loop for the specified number of iterations
for ((i = 1; i <= iterations; i++)); do
  # Generate the specified number of random numbers
  args=$(shuf -i 1-900 -n "$num_count" | tr '\n' ' ')
  
  # Store results of push_swap and checker_linux
  result=$(./push_swap $args | ./checker_linux $args)
  count=$(./push_swap $args | wc -l)
  
  # Colorize result
  if [ "$result" == "OK" ]; then
    color_result="${GREEN}OK${RESET}"
  else
    color_result="${RED}KO${RESET}"
  fi

  # Print everything on one line
  echo -e "$color_result $count"
done