#include <stdio.h>
#include <stdlib.h>

//int ft_strcmp(char *s1, char *s2);
//int ft_write(int fd, char *str, int size);
char *ft_strcpy(char *dest, char *src);

char *ft_strnew(int size, char c)
{
    char *new;

    new = malloc(sizeof(char) * (size + 1));
    new[size] = '\0';
    while (size--)
        new[size] = c;
    return (new);
}

int main(void)
{
    char *yo;
    char *xd;

    yo = ft_strnew(5, 'a');
    xd = ft_strnew(4, 'x');

    printf("%s\n", ft_strcpy(yo, xd));

    free(yo);
    free(xd);
//    printf("sizeof int: %ld\nsizeof char* %ld", sizeof(int), sizeof(char*));
}