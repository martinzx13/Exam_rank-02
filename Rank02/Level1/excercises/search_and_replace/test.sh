#!/bin/bash

# Compiler flags
CFLAGS="-Wall -Wextra -Werror"

# Compile the search_and_replace.c program
cc $CFLAGS -o search_and_replace search_and_replace_copy.c

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
    arg1="$1"
    arg2="$2"
    arg3="$3"
    expected_output="$4"
    test_number="$5"

    # Run the program
    output=$(./search_and_replace "$arg1" "$arg2" "$arg3")

    if [ "$output" == "$expected_output" ]; then
        print_colored "Test $test_number passed: Output matches desired output." "green"
    else
        print_colored "Test $test_number failed: Output does not match desired output." "red"
    fi
}

# Test cases
test_cases=(
    "Papache est un sabre" "a" "o" "Popoche est un sobre"
    "zaz" "art" "zul" ""
    "zaz" "r" "u" "zaz"
    # "jacob" "a" "b" "c" "e" ""
    "ZoZ eT Dovid oiME le METol." "o" "a" "ZaZ eT David aiME le METal."
    "wNcOre Un ExEmPle Pas Facilw a Ecrirw" "w" "e" "eNcOre Un ExEmPle Pas Facile a Ecrire"
)

# Run test cases
for ((i=0; i<${#test_cases[@]}; i+=4)); do
    arg1="${test_cases[$i]}"
    arg2="${test_cases[$i+1]}"
    arg3="${test_cases[$i+2]}"
    expected_output="${test_cases[$i+3]}"
    run_test "$arg1" "$arg2" "$arg3" "$expected_output" "$((i/4+1))"
done

# Clean up the compiled program
rm search_and_replace
