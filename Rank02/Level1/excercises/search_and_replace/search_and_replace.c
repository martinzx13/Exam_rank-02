#include <unistd.h>

void ft_printchar(char c)
{
    write(1, &c, 1);
}

void ft_search_replace(char *s, char a, char b)
{
    int i;
    int num;

    i = 0;
    num = 0;
    while (s[i])
    {
        if (s[i] == a)
        {
            ft_printchar(b);
            num = 1;
        }
        else
            ft_printchar(s[i]);
        i++;
    }
    if (!num)
            write(1, "\n", 1);
}

int main(int arg, char **argv)
{
    if (arg == 4 && !argv[2][1] && !argv[3][1])
        ft_search_replace(argv[1], *argv[2], *argv[3]);
    else
        write(1, "\n", 1);
}