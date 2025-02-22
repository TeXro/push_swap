CC = cc
SRC = ft_stack.c utils.c ft_int_split.c check.c ft_long_join.c \
	  moves_ps.c moves_r.c moves_rr.c sort.c
OBJ = ${SRC:.c=.o}
CFLAGS =
NAME = push_swap.a

all : $(NAME)
	cc main.c $(NAME) -o push_swap && rm -f $(OBJ) $(NAME)

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