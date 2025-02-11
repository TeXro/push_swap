CC = cc
SRC = utils.c ft_split.c ft_atoi.c check.c
OBJ = ${SRC:.c=.o}
CFLAGS =
NAME = push_swap.a

all : $(NAME)
	cc main.c $(NAME) -o push_swap && rm -f $(OBJ)

re : fclean all

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

.PHONY: all re clean fclean