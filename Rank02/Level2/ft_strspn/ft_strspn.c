#include <unistd.h>
#include <string.h>
#include <stdio.h>

const char *ft_strchr(const char *s, int c)
{
    int i; 

    i = 0;
    while(s[i])
    {
        if (s[i] == c)
            return((char *)s);
        i++;
    }
    return ((void *) 0);
}


size_t	ft_strspn(const char *s, const char *accept)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (!ft_strchr(accept, s[i]))
            break;
        i++;
    }
    return (i);
}
int main()
{
    char *s;
    char *accept;

    s =      "Hola como estas ";
    accept = "Hola perro parcero";
    if (strspn(s, accept) ==  ft_strspn(s, accept))
        printf("siuwwwwww\n");
    else 
        printf("nooooo\nmy :%ld:\noriginal :%ld:\n", ft_strspn(s, accept), strspn(s, accept));

}