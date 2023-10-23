#include <stdio.h>
#include <stdio.h>
#include <string.h> // Include the original strcpy function
#include <stdbool.h>

char    *ft_strcpy(char *s1, char *s2)
{
    int i;
    
    i = 0;
    while (s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return (s1);
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

    // Buffer to hold results
    char result[100]; // Make sure it's large enough for the longest string

    bool all_tests_passed = true;

    for (int i = 0; i < num_tests; i++) {
        char *original_result = strcpy(result, test_strings[i]);
        char *your_result = ft_strcpy(result, test_strings[i]);

        if (strcmp(original_result, your_result) == 0) {
            printf("Test %d: Passed\n", i + 1);
        } else {
            printf("Test %d: Failed\n", i + 1);
            all_tests_passed = false;
        }
    }

    if (all_tests_passed) {
        printf("All tests passed!\n");
    } else {
        printf("Some tests failed.\n");
    }

    return 0;
}