#include <unistd.h>
#include <stdio.h>

int	ft_atoi(const char *str)
{
    int i;
    int sign;
    int num;

    i = 0;
    sign = 1;
    num = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    if (str[i] == '+')
        i++;
    
    while (str[i] >= '0' && str[i] <= '9')
    {
        num = num  * 10 + (str[i] - '0');
        i++;
    }
    return (num * sign);
    
}

void run_test(const char *input, int expected_output, int test_number) {
    int result = ft_atoi(input);

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
    run_test("     123", 123, 1);
    run_test("-456", -456, 2);
    run_test("0", 0, 3);
    run_test("42", 42, 4);
    run_test("-100", -100, 5);
    run_test("99999", 99999, 6);
    run_test("2147483647", 2147483647, 7);  // INT_MAX
    run_test("-2147483648", -2147483648, 8);  // INT_MIN
    run_test("abc", 0, 9);  // Invalid input

    return 0;
}