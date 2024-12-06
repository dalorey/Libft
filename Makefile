# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlorenzo <dlorenzo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 07:25:06 by dlorenzo          #+#    #+#              #
#    Updated: 2024/12/06 09:49:04 by dlorenzo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
NAME = libft.a
LFLAGS = -L. -lft

# Files
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c \
	ft_bzero.c ft_memset.c ft_memcpy.c ft_memmove.c
OBJ = $(SRC:.c=.o)

# Test environment
# test file name
TEST = test
# test file source
TEST_SRC = test.c
# test target executable
TEST_BIN =  $(TEST)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(TEST_BIN)

re: fclean all test

# Test objective
test: $(NAME) $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) $(LFLAGS) -o $(TEST_BIN)
