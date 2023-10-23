#!/bin/bash

# Compiler flags
CFLAGS="-Wall -Wextra -Werror"

# Compile the ft_putstr.c program with the function
gcc $CFLAGS -o ft_putstr ft_putstr.c

# Check if compilation was successful
if [ $? -ne 0 ]; then
    echo -e "\e[91mCompilation failed.\e[0m"
    exit 1
fi

# Function to print colored output
print_colored() {
    if [ "$2" == "red" ]; then
        echo -e "\e[91m$1\e[0m"
    elif [ "$2" == "green" ]; then
        echo -e "\e[92m$1\e[0m"
    else
        echo "$1"
    fi
}

# Function to run a test case
run_test() {
    input="$1"
    expected_output="$2"
    test_number="$3"

    # Run the program
    output=$(echo -e "$input" | ./ft_putstr)

    if [ "$output" == "$expected_output" ]; then
        print_colored "Test $test_number passed: Output matches desired output." "green"
    else
        print_colored "Test $test_number failed: Output does not match desired output." "red"
    fi
}

# Test cases
test_cases=(
    "Hello, World!" "Hello, World!\n"
    "12345" "12345\n"
    "" "\n"
    "Special Characters: \t\n\"'&" "Special Characters: \t\n\"'&\n"
    "A\nB\nC\n" "A\nB\nC\n\n"
)

# Run test cases
for ((i=0; i<${#test_cases[@]}; i+=2)); do
    input="${test_cases[$i]}"
    expected_output="${test_cases[$i+1]}"
    run_test "$input" "$expected_output" "$((i/2+1))"
done

# Clean up the compiled program
rm ft_putstr
