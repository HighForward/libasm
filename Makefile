SRCS		=	ft_strlen.s	\
				ft_strcpy.s	\
				ft_strcmp.s	\
				ft_strdup.s	\
				ft_write.s	\
				ft_read.s	\

NAME		=	libasm.a

OBJS		=	${SRCS:.s=.o}


CC			=	nasm -f macho64

RM			=	rm -f

$(NAME): ${OBJS}
				@ar -sucr $(NAME) ${OBJS}
				@echo "\033[1;32m > Building <\033[0m\033[1;31m libft.a\033[0m"

.s.o:		${OBJS}
			@${CC} $< -o ${<:.s=.o}

all: $(NAME)

clean:
				@${RM} ${OBJS}

fclean: clean
				@${RM} $(NAME)
				@echo "\033[1;31m > Deleting <\033[0m\033[1;35m libft.a\033[0m"

re:	fclean all


.PHONY: all clean fclean re bonus
