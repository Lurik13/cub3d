# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atu <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 21:38:16 by atu               #+#    #+#              #
#    Updated: 2024/03/14 11:14:53 by aboyreau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = cub3D
CFLAGS += -Wall -Wextra -Werror
CPPFLAGS += -Iminilibx-linux -Ilibft
LDLIBS += -lft -lmlx
LDFLAGS += -Llibft -Lminilibx-linux

SRC = cub3d parse_attrs

SRCS = $(addsuffix .c,$(SRC))
OBJS = $(addsuffix .o,$(SRC))

all: deps $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(NAME) $(LDLIBS)

deps:
	$(MAKE) -C libft
	$(MAKE) -C minilibx-linux

%.o: %.c
	$(CC) $(CFLAGS) -c $(CPPFLAGS) $< -o $@

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all
