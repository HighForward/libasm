#include <stdio.h>
#include <stdlib.h>
#include <libc.h>

typedef struct	s_list
{
	void *data;
	struct s_list *next;
}				t_list;

void	ft_lstclear(t_list **lst)
{
	t_list *now;
	t_list *after;

	now = *lst;
	if (lst && *lst)
	{
		while (now)
		{
			if (now->next)
				after = now->next;
			else
				after = NULL;
			free(now);
			now = after;
		}
		*lst = NULL;
	}
}

t_list	*ft_lstnew(void *content)
{
	t_list *new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new->data = content;
	new->next = NULL;
	return (new);
}

char *ft_strnew(int size, char c)
{
	char *new;

	new = malloc(sizeof(char) * (size + 1));
	new[size] = '\0';
	while (size--)
		new[size] = c;
	return (new);
}

int ft_strcmp(char *s1, char *s2);
int ft_write(int fd, char *str, int size);
char *ft_strcpy(char *dest, char *src);
int ft_read(int fd, void *buffer, unsigned int count);
int ft_strlen(char *str);
char *ft_strdup(char *str);
int	ft_list_size(t_list *list);

int main(void)
{
	char *string;
	char *src;
	char *dest;
	char *s1;
	char *s2;
	char *dupp;
	char *str;
	char *readed;
	int	fd[2];
	int ret;
	int x;
	t_list *list;

	printf("\033[01;33m#-------------------------------------#\033[0m\n");
	printf("\033[01;33m#------------- ft_strlen -------------#\033[0m\n");
	printf("\033[01;33m#-------------------------------------#\033[0m\n");
	string = "Je suis une string.";
	printf("\033[1;31m-- STRING -- :\033[0m \033[1;36m%s\033[0m\n", string);
	printf("\033[0;31m REAL :\033[0m \033[0;36m%d\033[0m\n", (int)strlen(string));
	printf("\033[0;31m ASM  :\033[0m \033[0;36m%d\033[0m\n", (int)ft_strlen(string));
	printf("\033[01;33m#-------------------------------------#\033[0m\n");
	printf("\033[01;33m#------------- ft_strcpy -------------#\033[0m\n");
	printf("\033[01;33m#-------------------------------------#\033[0m\n");
	dest = ft_strnew(9, 'A');
	src = ft_strnew(4, 'Z');
	printf("\033[1;31m--  DEST  -- :\033[0m \033[1;36m%s\033[0m\n", dest);
	printf("\033[1;31m-- SOURCE -- :\033[0m \033[1;36m%s\033[0m\n", src);
	printf("\033[0;31m REAL :\033[0m \033[0;36m%s\033[0m\n", strcpy(dest, src));
	printf("\033[0;31m ASM  :\033[0m \033[0;36m%s\033[0m\n", ft_strcpy(dest, src));
	s1 = "Yo l'ekipe moi c'est S1";
	s2 = "Yo l'ekipe moi c'est S2";
	printf("\033[01;33m#-------------------------------------#\033[0m\n");
	printf("\033[01;33m#------------- ft_strcmp -------------#\033[0m\n");
	printf("\033[01;33m#-------------------------------------#\033[0m\n");
	printf("\033[1;31m--  S1  -- :\033[0m \033[1;36m%s\033[0m\n", s1);
	printf("\033[1;31m--  S2  -- :\033[0m \033[1;36m%s\033[0m\n", s2);
	printf("\033[0;31m REAL :\033[0m \033[0;36m%d\033[0m\n", strcmp(s1, s2));
	printf("\033[0;31m ASM  :\033[0m \033[0;36m%d\033[0m\n", ft_strcmp(s1, s2));
	dupp = NULL;
	str = "Je suis une string duplicable";
	printf("\033[01;33m#-------------------------------------#\033[0m\n");
	printf("\033[01;33m#------------- ft_strdup -------------#\033[0m\n");
	printf("\033[01;33m#-------------------------------------#\033[0m\n");
	printf("\033[1;31m--  dup  -- :\033[0m \033[1;36m%s\033[0m\n", dupp);
	printf("\033[1;31m--  str  -- :\033[0m \033[1;36m%s\033[0m\n", str);
	printf("\033[0;31m REAL :\033[0m \033[0;36m%s\033[0m\n", dupp = strdup(str));
	free(dupp);
	printf("\033[0;31m ASM  :\033[0m \033[0;36m%s\033[0m\n", dupp = ft_strdup(str));
	free(dupp);
	printf("\033[01;33m#-------------------------------------#\033[0m\n");
	printf("\033[01;33m#-------------  ft_write  ------------#\033[0m\n");
	printf("\033[01;33m#-------------------------------------#\033[0m\n");

	fd[0] = dup(1);
	fd[1] = open("file_descriptor", O_RDWR | O_CREAT | O_TRUNC);
	dup2(fd[1], 1);

	write(1, "YO LEK1PAGE", 11);

	dup2(fd[0], 1);
	close(fd[0]);
	close(fd[1]);
	fd[0] = open("file_descriptor", O_RDONLY);
	readed = ft_strnew(10, 'q');
	ret = read(fd[0], readed, 11);
	printf("\033[0;31m REAL :\033[0m \033[0;36m%s\033[0m\n", readed);
	close(fd[0]);
	free(readed);

	fd[0] = dup(1);
	fd[1] = open("file_descriptor", O_RDWR | O_CREAT | O_TRUNC);
	dup2(fd[1], 1);

	ft_write(1, "YO LEK1PAGE", 11);

	dup2(fd[0], 1);
	close(fd[0]);
	close(fd[1]);
	fd[0] = open("file_descriptor", O_RDONLY);
	readed = ft_strnew(10, 'q');
	ret = read(fd[0], readed, 11);
	printf("\033[0;31m ASM  :\033[0m \033[0;36m%s\033[0m\n", readed);
	close(fd[0]);
	free(readed);

	printf("\033[01;33m#-------------------------------------#\033[0m\n");
	printf("\033[01;33m#-------------  ft_read  -------------#\033[0m\n");
	printf("\033[01;33m#-------------------------------------#\033[0m\n");
	fd[0] = open("test_read", O_RDONLY);
	readed = ft_strnew(27, 0);
	read(fd[0], readed, 27);
	printf("\033[0;31m REAL :\033[0m \033[0;36m%s\033[0m\n", readed);
	close(fd[0]);
	free(readed);
	fd[0] = open("test_read", O_RDONLY);
	readed = ft_strnew(27, 0);
	ft_read(fd[0], readed, 27);
	printf("\033[0;31m ASM  :\033[0m \033[0;36m%s\033[0m\n", readed);
	close(fd[0]);
	free(readed);
	printf("\033[01;33m#-------------------------------------#\033[0m\n");
	printf("\033[01;33m#------------ ft_lst_size ------------#\033[0m\n");
	printf("\033[01;33m#-------------------------------------#\033[0m\n");
	t_list *temp;
	x = 0;
	list = ft_lstnew("NON");
	temp = list;
	while (x < 3)
	{
		list->next = ft_lstnew("XD");
		list = list->next;
		x++;
	}
	list = temp;
	temp = list;
	printf("\033[0;31m ASM  :\033[0m \033[0;36m%d\033[0m\n", ft_list_size(temp));
	printf("\033[01;33m#-------------------------------------#\033[0m\n");
	ft_lstclear(&temp);
}