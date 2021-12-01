# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/15 21:19:34 by ymirna            #+#    #+#              #
#    Updated: 2021/11/27 19:32:29 by ymirna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

HEADER	=	ft_printf.h

SRC		=	ft_printf.c ft_print_csdiu.c ft_print_hex.c ft_to_hex.c

OBJS	=	$(SRC:%.c=%.o)

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -I$(HEADER)

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(HEADER)
		ar rcs $(NAME) $?

%.o		:	%.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

clean	:	
		rm -f $(OBJS)

fclean	:	clean
		rm -f $(NAME)

re		:	fclean all
