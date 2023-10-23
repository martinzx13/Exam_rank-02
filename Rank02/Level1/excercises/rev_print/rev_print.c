#include <stdio.h>

void ft_print_char(char c)
{
    printf("%c", c);
}

void ft_reverse(char *string)
{
    int i;
    i = 0;

    while(string[i])
        i++;
    while(i > -1)
        ft_print_char(string[i--]);
}

int main(int argc, char **argv)
{
    if (argc > 2)
        return (0);

    ft_reverse(argv[1]);
    printf("\n");
    return 0;
}