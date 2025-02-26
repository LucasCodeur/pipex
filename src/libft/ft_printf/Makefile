# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 10:37:40 by lud-adam          #+#    #+#              #
#    Updated: 2025/02/10 17:11:25 by lud-adam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
CC := cc
CFLAGS := -Wall -Werror -Wextra
SRC := ft_printf.c ft_printf_utils.c
OBJ := $(SRC:.c=.o)
H_FILES := ft_printf.h
LIBFT_DIR := ..
LIBFT := $(LIBFT_DIR)/libft.a
$(MAKE) := $(MAKE) -j --no-print-directory

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c $(H_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

lib: 
	@$(MAKE) -C $(LIBFT_DIR) -j$(nproc)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
