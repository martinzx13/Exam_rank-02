#!/bin/bash

# Compiler flags
CFLAGS="-Wall -Wextra -Werror"

# Compile the camel_to_snake.c program
gcc $CFLAGS -o camel_to_snake camel_to_snake.c

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
    output=$(./camel_to_snake "$input")

    if [ "$output" == "$expected_output" ]; then
        print_colored "Test $test_number passed: Output matches desired output." "green"
    else
        print_colored "Test $test_number failed: Output does not match desired output." "red"
    fi
}

# Additional Test Cases
test_cases+=(
    "hello" "hello"
    "camelCase" "camel_case"
    "lowercase" "lowercase"
    "simpleOne" "simple_one"
    "iAmATestCase" "i_am_a_test_case"
    "testingOneTwoThree" "testing_one_two_three"
    "mixedWith123Numbers" "mixed_with123_numbers"
    "leadingDigit123" "leading_digit123"
)

# Run additional test cases
for ((i=${#test_cases[@]}-20; i<${#test_cases[@]}; i+=2)); do
    input="${test_cases[$i]}"
    expected_output="${test_cases[$i+1]}"
    run_test "$input" "$expected_output" "$((i/2+1))"
done

# Clean up the compiled program
rm camel_to_snake
