# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akloster <akloster@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/06 17:54:38 by akloster          #+#    #+#              #
#    Updated: 2024/12/12 13:09:02 by akloster         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM				=	rm -rf

SRC_DIR				=	src/

SRC				=	main.c

HEADERS				=	includes/cub3d.h

LIBft				=	libft/libft.a

OBJ_DIR				=	objs/

OBJ				=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

CC				=	cc

CFLAGS				=	-Wall -Wextra -Werror

NAME				=	cub3d

$(NAME):			$(OBJ_DIR) $(OBJ) 
				make -C./libft
				$(CC) $(OBJ) $(LIBft) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all:				$(NAME)

$(OBJ_DIR)%.o:			$(SRC_DIR)%.c $(HEADERS)
				@mkdir -p $(dir $@)
				$(CC) $(CFLAGS) -Iincludes -I/usr/include -Imlx_linux -O3 -c $< -o $@


$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)

clean:
				make clean -C./libft
				$(RM) $(OBJ_DIR)

fclean:				clean
				make fclean -C./libft
				$(RM) $(NAME) $(OBJ_DIR)

re:				fclean $(NAME)


.PHONY:			all clean fclean re
