#include <stdio.h>

int    ft_strcmp(char *s1, char *s2)
{
    while (*s1 && *s2 && *s1 == *s2)
    {
        *s1++;
        *s2++;
    }
    return (*s1 - *s2);
}

void run_test(char *s1, char *s2, int expected_output, int test_number) {
    int result = ft_strcmp(s1, s2);

    if (result == expected_output) {
        printf("Test %d passed: Output matches expected result.\n", test_number);
    } else {
        printf("Test %d failed: Output does not match expected result.\n", test_number);
        printf("Expected: %d\n", expected_output);
        printf("Received: %d\n", result);
    }
}

int main() {
    // Test cases
    run_test("abc", "abc", 0, 1);  // Equal strings
    run_test("abc", "def", -3, 2);  // s1 < s2
    run_test("def", "abc", 3, 3);  // s1 > s2
    run_test("hello", "world", -14, 4);  // Different lengths
    run_test("", "", 0, 5);  // Empty strings
    run_test("same", "same", 0, 6);  // Equal strings
    run_test("12345", "123", 2, 7);  // s1 > s2
    run_test("abc", "abcd", -1, 8);  // s1 < s2

    return 0;
}
