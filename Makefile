# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 11:11:52 by lud-adam          #+#    #+#              #
#    Updated: 2025/03/17 14:04:33 by lud-adam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex

SRC_DIR := src
FTPRINTF_DIR := src/libft/ft_printf
OBJ_DIR := obj
LIBFT_DIR := src/libft/
DEP_DIR := dep
INC_DIR := include

SRC = \
	$(SRC_DIR)/execution.c \
	$(SRC_DIR)/free.c \
	$(SRC_DIR)/functions_utils.c \
	$(SRC_DIR)/get_path.c \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/process.c

LIBFT_SRC = \
	$(LIBFT_DIR)ft_atoi.c     $(LIBFT_DIR)ft_isascii.c  $(LIBFT_DIR)ft_memcmp.c      $(LIBFT_DIR)ft_putendl_fd.c $(LIBFT_DIR)ft_strdup.c    $(LIBFT_DIR)ft_strlen.c   $(LIBFT_DIR)ft_strtrim.c	\
	$(LIBFT_DIR)ft_calloc.c   $(LIBFT_DIR)ft_isprint.c  $(LIBFT_DIR)ft_memmove.c     $(LIBFT_DIR)ft_putstr_fd.c  $(LIBFT_DIR)ft_strjoin.c   $(LIBFT_DIR)ft_strncmp.c  $(LIBFT_DIR)ft_tolower.c \
	$(LIBFT_DIR)ft_isalnum.c  $(LIBFT_DIR)ft_itoa.c     $(LIBFT_DIR)ft_memset.c      $(LIBFT_DIR)ft_split.c      $(LIBFT_DIR)ft_strlcat.c   $(LIBFT_DIR)ft_strnstr.c  $(LIBFT_DIR)ft_toupper.c \
	$(LIBFT_DIR)ft_isalpha.c  $(LIBFT_DIR)ft_memchr.c   $(LIBFT_DIR)ft_putchar_fd.c  $(LIBFT_DIR)ft_strchr.c     $(LIBFT_DIR)ft_strlcpy.c   $(LIBFT_DIR)ft_strrchr.c \
	$(LIBFT_DIR)ft_lstnew_bonus.c	$(LIBFT_DIR)ft_lstadd_front_bonus.c	$(LIBFT_DIR)ft_lstsize_bonus.c $(LIBFT_DIR)ft_lstlast_bonus.c	$(LIBFT_DIR)ft_lstadd_back_bonus.c \
	$(LIBFT_DIR)ft_lstdelone_bonus.c $(LIBFT_DIR)ft_lstclear_bonus.c	$(LIBFT_DIR)ft_lstiter_bonus.c	$(LIBFT_DIR)ft_lstmap_bonus.c \


LIBFT_INC = $(LIBFT_DIR)libft.h  

OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEP := $(OBJ:$(OBJ_DIR)/%.o=$(DEP_DIR)/%.d)

MAKE := make -j
CC := cc
CFLAGS := -Wall -Wextra -Werror
INC := -I$(INC_DIR) -I/usr/include
LIBFT := $(LIBFT_DIR)libft.a

$(NAME): $(OBJ) $(LIBFT) 
	$(CC) $(CFLAGS) $(INC) $^ $(LIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/pipex.h Makefile $(LIBFT)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -MMD -MP -c $< -o $@

$(LIBFT): $(LIBFT_SRC) $(LIBFT_INC)
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
