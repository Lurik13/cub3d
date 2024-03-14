# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lribette <lribette@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 21:38:16 by atu               #+#    #+#              #
#    Updated: 2024/03/14 11:35:55 by aboyreau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = cub3D
CFLAGS += -Wall -Wextra -Werror
CPPFLAGS += -Iminilibx-linux -Ilibft
LDLIBS += -lft -lmlx -lXext -lX11 -lm -lz
LDFLAGS += -Llibft -Lminilibx-linux

SRC = cub3d parsing_map parse_attrs game

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
