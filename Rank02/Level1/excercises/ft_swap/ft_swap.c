#include <stdio.h>

void	ft_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int a = 9;
    int b = 12;
    printf(":%d:\n", a);
    printf(":%d:\n", b);
    ft_swap(&a, &b);
    printf("%c", '\n');
    printf(":%d:\n", a);
    printf(":%d:\n", b);

}