#include <stdio.h>
#include <stdlib.h>

//int ft_strcmp(char *s1, char *s2);
//int ft_write(int fd, char *str, int size);
//char *ft_strcpy(char *dest, char *src);
//int ft_read(int fd, void *buffer, unsigned int count);
int ft_strlen(char *str);
char *ft_strdup(char *str);

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
    char *str;

    str = "yo l'ekipe";

//    yo = ft_strnew(5, 'a');
//    xd = ft_strnew(4, 'x');

//    ft_read(0, yo, 15);

//    free(yo);
//    free(xd);
    printf("%s\n", ft_strdup(str));
//    printf("sizeof int: %ld\nsizeof char* %ld", sizeof(int), sizeof(char*));
}