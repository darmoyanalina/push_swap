NAME := push_swap
CC := cc
CFLAGS := -Wall -Wextra -Werror

FT_PRINTF_DIR := ./ft_printf
FT_PRINTF := $(FT_PRINTF_DIR)/libftprintf.a

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
      quick_sort.c \
      ranking.c \
      main.c \
      bench.c \
      medium_sort.c

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(NAME): $(OBJ) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) -L$(FT_PRINTF_DIR) -lftprintf -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
