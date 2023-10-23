#include <stdio.h>

int main(int argc, char **argv)
{
    int start;

    if (argc == 2 )
    {
    start = 0;
    while (argv[1][start] == ' ' || argv[1][start] == '\t')
        start++;
    while(argv[1][start])
    {
        printf("%c", argv[1][start++] );
        if ( (argv[1][start] == ' ' 
        || argv[1][start] == '\t'))
            {
                printf("\n");
                return (0) ;
            }
    }
    }
    printf("\n");
    return (1);
}