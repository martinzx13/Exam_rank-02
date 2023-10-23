#include <stdio.h>
#include <string.h> // Include the original strlen function
#include <stdbool.h>


int ft_strlen(char *s1)
{
    int i;

    i = 0;
    while (s1[i])
    {
        i++;
    }
    return (i);
    
}

int main(void)
{
    // Test cases
    char *test_strings[] = {
        "Hello, World!",
        "This is a test string.",
        "12345",
        "",
        "Another example",
        "Short"
    };

    // Number of test cases
    int num_tests = sizeof(test_strings) / sizeof(test_strings[0]);

    bool all_tests_passed = true;

    for (int i = 0; i < num_tests; i++) {
        int original_length = (int)strlen(test_strings[i]);
        int your_length = ft_strlen(test_strings[i]);

        if (original_length == your_length) {
            printf("Test %d: Passed\n", i + 1);
        } else {
            printf("Test %d: Failed\n", i + 1);
            all_tests_passed = false;
        }
    }

    if (all_tests_passed) {
        printf("All tests passed! Good Job\n");
    } else {
        printf("Some tests failed.\n");
    }

    return 0;
}