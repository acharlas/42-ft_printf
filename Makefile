# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acharlas <acharlas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 11:01:37 by acharlas          #+#    #+#              #
#    Updated: 2019/11/13 12:02:26 by acharlas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_atoi.c \
	  ft_create_str.c \
	  ft_fill_struct.c \
	  ft_isdigit.c \
	  ft_itoa_base.c \
	  ft_printf.c \
	  ft_strdup.c \
	  ft_strjoin.c \
	  ft_strlen.c \
	  init_struct.c

@CC = gcc

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g3 -I libft 

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean :
	rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all
