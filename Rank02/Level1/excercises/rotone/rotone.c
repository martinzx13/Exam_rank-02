#include <stdio.h>

void ft_printchar(char c)
{
    printf("%c", c);
}

void ft_rotone(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            ft_printchar((s[i] - 'a' + 1) % 26 + 'a');
        else if (s[i]>= 'A' && s[i] <= 'Z')
            ft_printchar((s[i] - 'A' + 1) % 26 + 'A');
        else 
            ft_printchar(s[i]);
        i++;
    }
    
}

int main(int argc, char **argv)
{
    if (argc == 2)
        ft_rotone(argv[1]);
    printf("\n");
}