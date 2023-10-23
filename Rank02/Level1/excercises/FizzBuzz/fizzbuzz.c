#include <stdio.h>

void ft_fizzbuzz()
{
    int number;

    number = 1;
    while (number <= 100)
    {
        if (number%3 == 0 && number%5 == 0)
            printf("%s", "fizzbuzz\n");
        else if (number%3 == 0)
            printf("%s", "fizz\n");
        else if (number%5 == 0)
            printf("%s", "buzz\n");
        
        else
            printf("%d\n", number);
        number ++;
    }
    
}

int main(void)
{
    ft_fizzbuzz();
    return (0);
}