# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyasuhir <gyasuhir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/05 10:34:45 by gyasuhir          #+#    #+#              #
#    Updated: 2025/01/06 15:10:44 by gyasuhir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		 = ft_printf.c utils.c

OBJECTS		 = $(SRCS:%.c=%.o)

INCLUDES	 = ft_printf.h

NAME		 = libftprintf.a

VALGRIND_LOG = valgrind.log

all: $(NAME)

$(NAME): $(OBJECTS)

%.o: %.c
	@cc -Wall -Wextra -Werror -c $< $(INCLUDES)
	@ar rcs $(NAME) $@

clean:
	rm -f $(OBJECTS) *.h.gch

fclean: clean
	rm -f $(NAME)

re: fclean all

valgrind:
	@valgrind --leak-check=full \
	--show-reachable=yes \
	--show-leak-kinds=all -s \
	--track-origins=yes \
	--log-file=$(VALGRIND_LOG) \
	./$(NAME)
	@cat $(VALGRIND_LOG)

.PHONY: all clean fclean re