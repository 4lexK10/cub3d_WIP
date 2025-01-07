# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: linaboumahdi <linaboumahdi@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/06 17:54:38 by akloster          #+#    #+#              #
#    Updated: 2025/01/07 00:57:09 by linaboumahd      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
RM          = rm -rf
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iincludes

# Main project
SRC_DIR     = src/
SRC         = $(wildcard $(SRC_DIR)*.c)

# GNL (Get Next Line)
GNL_DIR     = GNL/
GNL_SRC     = $(wildcard $(GNL_DIR)*.c)

# Headers
HEADERS     = includes/cub3d.h GNL/get_next_line.h

# Libft
LIBft       = libft/libft.a

# Object files
OBJ_DIR     = objs/
SRC_OBJ     = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))
GNL_OBJ     = $(patsubst $(GNL_DIR)%.c, $(OBJ_DIR)%.o, $(GNL_SRC))
OBJ         = $(SRC_OBJ) $(GNL_OBJ)

# Output binary
NAME        = cub3d

# Targets
all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@make -C ./libft
	@echo "Linking $(NAME)..."
	$(CC) $(OBJ) $(LIBft) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	@echo "Compiling $< to $@..."
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(GNL_DIR)%.c $(HEADERS)
	@echo "Compiling $< to $@..."
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@make clean -C ./libft
	$(RM) $(OBJ_DIR)

fclean: clean
	@make fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
