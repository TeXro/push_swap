CC = cc
SRC = utils.c ft_int_split.c check.c moves.c ft_long_join.c
OBJ = ${SRC:.c=.o}
CFLAGS =
NAME = push_swap.a

all : $(NAME)
	cc fix.c $(NAME) -o push_swap && rm -f $(OBJ) $(NAME)

re : fclean all

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME) push_swap

.PHONY: all re clean fclean