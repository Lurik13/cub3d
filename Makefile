# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lribette <lribette@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 21:38:16 by atu               #+#    #+#              #
#    Updated: 2024/03/15 08:21:52 by aboyreau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = cub3D
CFLAGS += -Wall -Wextra -Werror -g
CPPFLAGS += -Iminilibx-linux -Ilibft
LDLIBS += -lft -lmlx -lXext -lX11 -lm -lz
LDFLAGS += -Llibft -Lminilibx-linux

SRC = cub3d \
	  parsing_map/check_recursive parsing_map/parsing_map parsing_map/parsing_utils \
	  parse_attrs \
	  game \
	  renderer/render

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

re: fclean all
