# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akloster <akloster@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/06 17:54:38 by akloster          #+#    #+#              #
#    Updated: 2024/12/06 18:00:40 by akloster         ###   ########.fr        #
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

CFLAGS				=	-Iincludes -Wall -Wextra -Werror

NAME				=	cub3d

$(NAME):			$(OBJ_DIR) $(OBJ) 
				make -C./libft
				$(CC) $(CFLAGS) $(OBJ) $(LIBft) 

all:				$(NAME)

$(OBJ_DIR)%.o:			$(SRC_DIR)%.c $(HEADERS)
				@mkdir -p $(dir $@)
				$(CC) $(CFLAGS) -c $< -o $@


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
