# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marthur- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/08 15:36:09 by marthur-          #+#    #+#              #
#    Updated: 2018/09/08 15:36:11 by marthur-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wextra -Wall -Werror

NAME = eval_expr

SRC = src/evalexpr.c src/help_func.c src/main.c src/stack.c\
		src/checks.c src/opers.c

all: $(NAME)

$(NAME):
		@gcc $(FLAGS) $(SRC) -o $(NAME)

fclean:
		@rm -f $(NAME)

re: fclean all
