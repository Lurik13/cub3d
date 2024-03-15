# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lribette <lribette@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 21:38:16 by atu               #+#    #+#              #
#    Updated: 2024/03/15 04:23:30 by aboyreau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = cub3D
CFLAGS += -Wall -Wextra -Werror -g
CPPFLAGS += -Iminilibx-linux -Ilibft
LDLIBS += -lft -lmlx -lXext -lX11 -lm -lz
LDFLAGS += -Llibft -Lminilibx-linux

SRC = cub3d Parsing_Map/check_recursive Parsing_Map/parsing_map \
		Parsing_Map/parsing_utils parse_attrs game 

LIBS = libft/libft.a minilibx-linux/libmlx.a

SRCS = $(addsuffix .c,$(SRC))
OBJS = $(addsuffix .o,$(SRC))

all: $(NAME)

$(NAME): $(LIBS) $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(NAME) $(LDLIBS)

$(LIBS):
	$(MAKE) -C libft
	$(MAKE) -C minilibx-linux

%.o: %.c
	$(CC) $(CFLAGS) -c $(CPPFLAGS) $< -o $@

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C minilibx-linux clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	$(MAKE) -C minilibx-linux clean
	rm -f $(NAME)
