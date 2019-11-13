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

SRC = ./srclib/ft_atoi.c \
	  ./srcstruct/ft_create_str.c \
	  ./srcstruct/ft_fill_struct.c \
	  ./srclib/ft_isdigit.c \
	  ./srclib/ft_itoa_base.c \
	  ft_printf.c \
	  ./srclib/ft_strdup.c \
	  ./srclib/ft_strjoin.c \
	  ./srclib/ft_strlen.c \
	  ./srcstruct/init_struct.c

@CC = gcc

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g3 -I headers

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean :
	rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all
