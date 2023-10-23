#include <unistd.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
    int i;
    int j;

    i = 0;
    while (s[i])
    {
        j = 0;
        while (reject[j])
        {
            if (s[i] == reject[j])
                return (i);
            j++;
        }
        i++;
    }
    return (i);
}

int run_test(const char *s, const char *reject, int test_number) {
    size_t result = ft_strcspn(s, reject);
    size_t expected_output = strcspn(s, reject);

    if (result == expected_output) {
        printf("Test %d passed: Output matches expected result.\n", test_number);
    } else {
        printf("Test %d failed: Output does not match expected result.\n", test_number);
        printf("Expected: %zu\n", expected_output);
        printf("Received: %zu\n", result);
    }
    return (expected_output);
}

int main() {
    // Test cases
    run_test("abcde", "12345", 1);  // No common characters
    run_test("abcde", "cde", 2);  // Common characters in the middle
    run_test("Hello, World!", "abcdefghijklmnopqrstuvwxyz", 3);  // No common characters with alphabets
    run_test("abcdefg", "a", 4);  // Common character at the start
    run_test("12345", "54321", 5);  // Reverse order
    run_test("this is a test", "aeiou", 6);  // Common characters in the middle
    run_test("testing", "aeiou", 7);  // All common characters
    run_test("abc", "xyz", 8);  // No common characters
    printf("%d\n", run_test("lllxyz", "xyz", 8));  // No common characters


    return 0;
}