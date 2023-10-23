#include <stdio.h>

void	ft_putstr(char *str)
{
    char *temp_str;

    if (!str)
        return ;
    temp_str = str;
    while (*temp_str)
    {
        printf("%c", *temp_str);
        temp_str++;
    }
}

int main(void)
{

    char *str1 = "Hello, World!" "Hello, World!\n";
    char *str2 = "12345" "12345\n";
    char *str3 = "" "\n";
    char *str4 = "Special Characters: \t\n\"'&" "Special Characters: \t\n\"'&\n";
    char *str5 = "A\nB\nC\n" "A\nB\nC\n\n";
    ft_putstr(str1);
    ft_putstr("\n");
    ft_putstr(str2);
    ft_putstr("\n");
    ft_putstr(str3);
    ft_putstr("\n");
    ft_putstr(str4);
    ft_putstr("\n");
    ft_putstr(str5);
    ft_putstr("\n");
    return (0);
}
