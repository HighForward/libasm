#include <stdio.h>
#include <stdlib.h>

int ft_strcmp(char *s1, char *s2);
int ft_write(int fd, char *str, int size);
char *ft_strcpy(char *dest, char *src);
int ft_read(int fd, void *buffer, unsigned int count);
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
    char *dest;
    char *src;
    char *string;
    char *read;

    dest = ft_strnew(9, 'A');
	src = ft_strnew(8, 'Z');
	string = "COUCOU";
	str = "YOOOOOOOO";

	ft_read(0, read, 5);
	///printf("%s\n", read);
	ft_write(1, "YO\n", 3);
	printf("%s\n", ft_strdup(str));
	printf("%d\n", ft_strcmp(string, str));
	printf("%s\n", ft_strcpy(dest, src));
	printf("%d\n", ft_strlen(str));
}