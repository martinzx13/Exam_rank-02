#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char    *ft_strdup(char *src)
{
    int len;
    int i;
    char *new_src;

    i = 0;
    len = 0;
    while (src[i])
        i++;
    
    new_src = malloc(sizeof(char) * len + 1);
    if (!new_src)
        return (NULL);
    i = 0;
    while(src[i])
    {
        new_src[i] = src[i];
        i++;
    }
    new_src[i] = '\0';

    return (new_src);
}

void run_test(const char *src, const char *expected, int test_number) {
    char *result = ft_strdup((char *)src);
    char *original_result = strdup(src);

    if (result && original_result && strcmp(result, expected) == 0 && strcmp(original_result, expected) == 0) {
        printf("Test %d passed: Output matches expected result.\n", test_number);
    } else {
        printf("Test %d failed: Output does not match expected result.\n", test_number);
        printf("Expected : \"%s\"\n", expected);
        printf("ft_strdup: \"%s\"\n", result);
        printf("strdup   : \"%s\"\n", original_result);
    }

    free(result);
    free(original_result);
}

int main() {
    // Test cases
    run_test("Hello, World!", "Hello, World!", 1);
    run_test("Test123", "Test123", 2);
    run_test("This is a test.", "This is a test.", 3);
    run_test("12345", "       12345", 4);
    run_test("", "", 5);

    return 0;
}