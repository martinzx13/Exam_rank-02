#include <stdio.h>

void ft_print(char c)
{
    printf("%c", c);
}

void ft_rotate(char *s)
{
    int i;

    i = 0;

    while (s[i])
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            ft_print((s[i] - 'a' + 13)% 26 + 'a');
        else if (s[i] >= 'A' && s[i] <= 'Z')
            ft_print((s[i] - 'A' + 13)% 26 + 'A');
        else
            ft_print(s[i]);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        ft_rotate(argv[1]);
        printf("\n");

    }
    printf("\n");
    return (0);
}