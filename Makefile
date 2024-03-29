# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lribette <lribette@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 21:38:16 by atu               #+#    #+#              #
#    Updated: 2024/03/28 09:59:21 by lribette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = cub3D
CFLAGS += -Wall -Wextra -Werror -g
CPPFLAGS += -Ilibs/minilibx-linux -Ilibs/libft -Iincludes
LDLIBS += -lft -lmlx -lXext -lX11 -lm -lz
LDFLAGS += -Llibs/libft -Llibs/minilibx-linux

SRC = cub3d \
	  parser/parsing_map/beginning_orientation \
	  parser/parsing_map/check_recursive parser/parsing_map/parsing_map \
	  parser/parsing_map/parsing_utils parser/parsing_map/print_map \
	  parser/parse_attrs \
	  game/game \
	  renderer/render renderer/map renderer/dda \
	  controls/init controls/controls

LIBS = libs/libft/libft.a libs/minilibx-linux/libmlx.a

SRCS = $(addprefix src/, $(addsuffix .c,$(SRC)))
OBJS = $(addprefix src/, $(addsuffix .o,$(SRC)))

all: deps $(NAME)

$(NAME): $(LIBS) $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(NAME) $(LDLIBS)

deps:
	$(MAKE) -C libs/libft
	$(MAKE) -C libs/minilibx-linux

%.o: %.c
	$(CC) $(CFLAGS) -c $(CPPFLAGS) $< -o $@

clean:
	$(MAKE) -C libs/libft clean
	$(MAKE) -C libs/minilibx-linux clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C libs/libft fclean
	$(MAKE) -C libs/minilibx-linux clean
	rm -f $(NAME)

re: fclean all
