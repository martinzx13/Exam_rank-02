#include <unistd.h>

void ft_print(char c)
{
    write(1, &c, 1);
}
void ft_camel_snake(char *s)
{
    int i;

    i = 0;
    while(s[i])
    {
       if (s[i] >= 'A' && s[i] <= 'Z')
        {
            ft_print('_');
            s[i] = s[i] + 32;            
        }
        ft_print(s[i]);
        i++;
    }
}





int main(int argc, char **argv)
{
    if (argc == 2)
    {
        ft_camel_snake(argv[1]);
        write(1, "\n", 1);
    }
    else
        write(1, "\n", 1);

    return (1);
}