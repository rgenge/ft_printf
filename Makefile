# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acosta-a <acosta-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 02:03:37 by acosta-a          #+#    #+#              #
#    Updated: 2022/05/19 14:08:59 by acosta-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable #
NAME = libftprintf.a

# Compilation #
CC = cc
FLAG = -Wall -Wextra -Werror
OPTCC=  -I. -c
RM = rm -f

# includes #

HEADER = ft_printf.h

# SOURCE FILES #
SRC = ft_printf.c ft_printf_utils_char.c ft_printf_utils_hex.c \
ft_printf_utils_nbr.c

SRC.O = $(SRC:.c=.o)

$(NAME): $(SRC.O) $(HEADER)
	$(CC) $(FLAG) $(OPTCC) $(SRC)
	ar rcs $(NAME) $(SRC.O)

all: $(NAME)

clean:
	$(RM) $(SRC.O) $(BONUS.O)
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
