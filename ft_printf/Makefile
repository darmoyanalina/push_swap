# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/23 20:20:24 by adarmoya          #+#    #+#              #
#    Updated: 2026/02/23 20:24:30 by adarmoya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f
AR := ar rsc

SRCS := \
	ft_printf.c ft_itoa.c ft_put_address.c ft_put_hex.c ft_putchar.c ft_putnbr.c ft_putnbr_un.c ft_putstr.c ft_strlen.c

OBJS := $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
