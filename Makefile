# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/29 13:27:42 by yyatsenk          #+#    #+#              #
#    Updated: 2017/11/15 16:20:04 by yyatsenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRCS := src/main.c 
SRCS +=	src/ant_maintain_and_free.c 
SRCS +=	src/ants_get_way.c 
SRCS +=	src/check1.c 
SRCS +=	src/check2.c 
SRCS +=	src/conect_struct_fill.c
SRCS += src/data_main_2.c 
SRCS +=	src/data_maintain.c 
SRCS +=	src/first_moments.c 
SRCS +=	src/line_struct_fill.c 
SRCS +=	src/make_ways.c 
SRCS +=	src/rebro.c
SRCS +=	src/way_down_maintain.c 
SRCS +=	src/way_maintain.c 

FLAGS = -Wall -Werror -Wextra 

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	@make -C ./ft_printf re
	@make re -C ./visu
	@gcc -o $(NAME) $(FLAGS) ./src/*.c ./libft/libft.a ./ft_printf/libftprintf.a
	@echo "\033[0;32mLemin done!\033[0m"

clean:
	@make clean -C ./libft
	@make clean -C ./visu
	@make -C ./ft_printf clean
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C ./libft
	@make fclean -C ./visu
	@make -C ./ft_printf fclean
	@rm -f $(NAME)

re: fclean all
