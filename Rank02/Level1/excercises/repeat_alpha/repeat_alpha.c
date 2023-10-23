#include <unistd.h>

void ft_putchar(char c, int num)
{
    while (num >= 0)
    {
        write(1, &c, 1);
        num--;
    }
}

void repeat_alpha(char *s1)
{
    int i;

    i = 0;
    while (s1[i])
    {
        if (s1[i] >= 'a' && s1[i] <= 'z')
            ft_putchar (s1[i], s1[i] - 'a');
        else if (s1[i] >= 'A' && s1[i]<= 'Z')
            ft_putchar (s1[i], s1[i] - 'A');
        else
            write(1, &s1[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        repeat_alpha(argv[1]);
        write(1, "\n", 1);
    }
    else
        write(1, "\n", 1);
    return (0);
}