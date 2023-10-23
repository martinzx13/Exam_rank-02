#include <unistd.h>

void ft_printchar(char c)
{
    write(1, &c, 1);
}

void ft_ulstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            ft_printchar(str[i] - 32);
        else if (str[i] >= 'A' && str[i] <= 'Z')
            ft_printchar(str[i] + 32);
        else
            ft_printchar(str[i]);
        i++;
    }
    
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        ft_ulstr(argv[1]);
        write(1, "\n", 1);
    }
    write(1, "\n", 1);
}