NAME := push_swap

CC := cc

CFLAGS := -Wall -Wextra -Werror

SRC = push_swap.c \
      parse.c \
	  push.c \
	  swap.c \
	  rotate.c \
	  r_rotate.c \
	  disorder.c \
	  ft_split.c \
	  lst_helpers.c \
	  check_dup.c \
	  insertion_sort.c \

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re