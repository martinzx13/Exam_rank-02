#!/bin/bash

# Compile the C file
cc -Wall -Wextra -Werror -o first_word first_word.c

# Define text colors
GREEN="\033[0;32m"
RED="\033[0;31m"
RESET="\033[0m"

# Test cases
echo -e "Test $> ./first_word \"FOR PONY\" | cat -e"
if [ "$(./first_word "FOR PONY" | cat -e)" = "FOR$" ]; then
    echo -e "${GREEN}Desired output${RESET} FOR$"
else
    echo -e "${RED}Unexpected output${RESET}"
    echo -e "${RED}Output $(./first_word "FOR PONY" | cat -e)"

fi

echo -e "Test $> ./first_word \"this        ...    is sparta, then again, maybe    not\" | cat -e"
if [ "$(./first_word "this        ...    is sparta, then again, maybe    not" | cat -e)" = "this$" ]; then
    echo -e "${GREEN}Desired output${RESET} this$"
else
    echo -e "${RED}Unexpected output${RESET}"
fi

echo -e "Test $> ./first_word \"   \" | cat -e"
if [ "$(./first_word "   " | cat -e)" = "\$" ]; then
    echo -e "${GREEN}Desired output${RESET} \$"
else
    echo -e "${RED}Unexpected output${RESET}"
fi

echo -e "Test $> ./first_word \"a\" \"b\" | cat -e"
if [ "$(./first_word "a" "b" | cat -e)" = "\$" ]; then
    echo -e "${GREEN}Desired output${RESET} \$"
else
    echo -e "${RED}Unexpected output${RESET}"
fi

echo -e "Test $> ./first_word \"  lorem,ipsum  \" | cat -e"
if [ "$(./first_word "  lorem,ipsum  " | cat -e)" = "lorem,ipsum$" ]; then
    echo -e "${GREEN}Desired output${RESET} lorem,ipsum$"
else
    echo -e "${RED}Unexpected output${RESET}"
fi

# Clean up the compiled executable
rm first_word
