# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haguezou <haguezou@student.1337.ma >       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 19:47:28 by haguezou          #+#    #+#              #
#    Updated: 2023/04/16 18:10:09 by haguezou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

SRCS = helper/ft_bzero.c helper/ft_calloc.c helper/ft_isdigit.c helper/ft_memcpy.c helper/ft_memmove.c helper/ft_split.c helper/ft_strdup.c helper/ft_strjoin.c helper/ft_strlen.c helper/ft_substr.c\
	rotate/r_rotate_action.c rotate/rotate_action.c \
	sort/sort_large.c sort/sort.c\
	swap/swap_actions.c \
	helper.c \
	helper2.c \
	push_swap.c \
	push/push_action.c

CC = cc

HEADER = pushswap.h

CFLAGS = -Wall -Werror -Wextra

OBJ = ${SRCS:.c=.o}


all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME) : $(OBJ) $(HEADER)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all