#!/bin/bash

# Compiler flags
CFLAGS="-Wall -Wextra -Werror"

# Compile the ulstr.c program
gcc $CFLAGS -o ulstr ulstr.c

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
    output=$(./ulstr "$input")

    if [ "$output" == "$expected_output" ]; then
        print_colored "Test $test_number passed: Output matches desired output." "green"
    else
        print_colored "Test $test_number failed: Output does not match desired output." "red"
    fi
}

# Test cases
test_cases=(
    "L'eSPrit nE peUt plUs pRogResSer s'Il staGne et sI peRsIsTent VAnIte et auto-justification."
    "l'EspRIT Ne PEuT PLuS PrOGrESsER S'iL STAgNE ET Si PErSiStENT vaNiTE ET AUTO-JUSTIFICATION."
    "S'enTOuRer dE sECreT eSt uN sIGnE De mAnQuE De coNNaiSSanCe.  "
    "s'ENtoUrER De SecREt EsT Un SigNe dE MaNqUe dE COnnAIssANcE.  "
    "3:21 Ba  tOut  moUn ki Ka di KE m'en Ka fe fot"
    "3:21 bA  ToUT  MOuN KI kA DI ke M'EN kA FE FOT"
    ""
    ""
)

# Run test cases
for ((i=0; i<${#test_cases[@]}; i+=2)); do
    input="${test_cases[$i]}"
    expected_output="${test_cases[$i+1]}"
    run_test "$input" "$expected_output" "$((i/2+1))"
done

# Clean up the compiled program
rm ulstr
