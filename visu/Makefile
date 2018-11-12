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

NAME = visu-hex

SRCS := main.c 
SRCS +=	ant_maintain_and_free.c 
SRCS +=	check1.c 
SRCS +=	check2.c 
SRCS +=	conect_struct_fill.c
SRCS += data_main_2.c 
SRCS +=	data_maintain.c 
SRCS +=	first_moments.c 
SRCS +=	line_struct_fill.c 
SRCS +=	make_ways.c 
SRCS +=	rebro.c
SRCS +=	way_down_maintain.c 
SRCS +=	way_maintain.c 
SRCS +=	part_0.c
SRCS +=	part_01.c 
SRCS +=	part_02.c 
SRCS +=	pu_help_2.c

FLAGS = -Wall -Werror -Wextra 

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	@make -C ./ft_printf re
	@cc -o $(NAME) -I /usr/local/include $(OBJ) -L /usr/local/bin -lmlx -framework OpenGL -framework AppKit ./libft/libft.a ./ft_printf/libftprintf.a
	@cp -i ./visu-hex ../
	@echo "\033[0;32mBonus done!\033[0m"

clean:
	@make clean -C ./libft
	@make -C ./ft_printf clean
	@rm -f ./*.o
	@echo "\033[0;32mCleaned\033[0m"

fclean: clean
	@make fclean -C ./libft
	@make -C ./ft_printf fclean
	@rm -f $(NAME)
	@rm -f ../visu-hex
	@echo "\033[0;32mFcleaned\033[0m"

re: fclean all
