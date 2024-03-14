# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 17:25:01 by atu               #+#    #+#              #
#    Updated: 2024/03/14 07:36:35 by aboyreau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h
CPPFLAGS += -I .
CFLAGS += -Wall -Wextra -Werror -c
LDLIBS += 
LDFLAGS += -Llibft
CC = cc

# echo $(find . -name "*.c") | sed "s/.c / /g" | sed "s= ./= =g" | sed "s|^./||g"
SRC = btree/btree_insert_data btree/btree_apply_suffix btree/btree_apply_prefix btree/btree_create_node btree/btree_apply_infix btree/btree_level_count btree/btree_search_item \
	tree/ft_treenew tree/ft_tree_addchild tree/ft_treedepth tree/ft_treeclear tree/ft_treeiter \
	io/ft_putnbr_fd io/ft_putstr_fd io/ft_putendl_fd io/ft_putchar_fd io/get_next_line \
	convert/ft_atoi convert/ft_itoa convert/ft_itoa_base convert/ft_uitoa convert/ft_uitoa_base \
	list/ft_lstclear list/ft_lstnew list/ft_lstiter list/ft_lstadd_front list/ft_lstdelone list/ft_lstsize list/ft_lstadd_back list/ft_lstmap list/ft_lstlast list/ft_lstrev list/ft_lst_from_tab list/ft_lst_to_tab \
	str/ft_strlen str/ft_strcontains str/ft_strtok str/ft_strreplace str/ft_strnjoin str/ft_indexof str/ft_split str/ft_strjoin str/ft_strmapi str/ft_strdup str/ft_strncmp str/ft_strlcat str/ft_strlcpy str/ft_striteri str/ft_strnstr str/ft_strtrim str/ft_strchr str/ft_substr str/ft_strrchr str/ft_strcjoin str/ft_strcmp str/ft_strstartswith str/ft_strendswith \
	mem/ft_memcpy mem/ft_calloc mem/ft_memmove mem/ft_memchr mem/ft_bzero mem/ft_memcmp mem/ft_memset mem/ft_grow mem/ft_quicksort mem/ft_fail_malloc \
	char/ft_isdigit char/ft_tolower char/ft_toupper char/ft_isalpha char/ft_isascii char/ft_isalnum char/ft_isprint \
	math/ft_min math/ft_max math/ft_power math/ft_abs \
	printf/ft_printf printf/handlers printf/handlers2 printf/flags \
	colors/ft_colors \
	vector/vector \
	parse/ft_bitargs \
	files/ft_files

SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))

all: $(NAME)

fuzzer: CFLAGS += -Ofast
fuzzer: LDLIBS += -fsanitize=address,fuzzer
fuzzer: fclean $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CPPFLAGS) -c $(CFLAGS) $< -o $@ $(LDLIBS)

debug: fclean $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

test: $(NAME)
	$(CC) $(CPPFLAGS) -Wall -Wextra -Werror tree/.test.c $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --quiet ./a.out
	rm a.out

test_printf: $(NAME)
	$(CC) $(CPPFLAGS) -Wall -Wextra -Werror printf/.test.c $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --quiet ./a.out
	rm a.out

re: fclean all
