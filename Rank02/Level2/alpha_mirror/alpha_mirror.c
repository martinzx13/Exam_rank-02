#include <unistd.h>
#include <stdio.h>

void ft_print(char c)
{
    write (1, &c, 1);
}

void ft_alpha_mirror(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] >= 'a' && s[i] <= 'z')
           ft_print( 'z' - (s[i] - 'a')); 
        else if (s[i] >= 'A' && s[i] <= 'Z')
            ft_print('Z' - (s[i] - 'A'));
        else 
            ft_print(s[i]);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        ft_alpha_mirror(argv[1]);
        write(1, "\n",1);
    }
    else 
        write(1, "\n",1);
}