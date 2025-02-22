CC = cc
SRC = push_swap.c sort.c big_sort.c ft_stack.c is_max.c\
	  utils.c ft_int_split.c check.c \
	  ft_long_join.c\
	  moves_ps.c moves_r.c moves_rr.c
OBJ = ${SRC:.c=.o}
CFLAGS = -g -Wall -Wextra -Werror
NAME = push_swap

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all