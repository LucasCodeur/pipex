# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 16:42:49 by lud-adam          #+#    #+#              #
#    Updated: 2025/02/24 18:23:56 by lud-adam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex
SRC_DIR := src
FTPRINTF_DIR := src/libft/ft_printf
OBJ_DIR := obj
LIBFT_DIR := src/libft/
DEP_DIR := dep
INC_DIR := include

SRC := $(shell find src -type f -name "*.c") 
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEP := $(OBJ:$(OBJ_DIR)/%.o=$(DEP_DIR)/%.d)

MAKE := make -j
CC := cc
CFLAGS := -Wall -Wextra -Werror
INC := -I$(INC_DIR) -I/usr/include -Imlx_linux
LIBFT := $(LIBFT_DIR)libft.a

$(NAME): $(OBJ) $(LIBFT) 
	$(CC) $(CFLAGS) $(INC) $^ $(LIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/fractol.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -MMD -MP -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR) $(DEP_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re: fclean $(NAME)

-include $(DEP)

.PHONY: all clean fclean re

