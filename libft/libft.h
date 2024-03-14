/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atu <atu@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:06:03 by atu               #+#    #+#             */
/*   Updated: 2024/03/14 11:58:27 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

# include "btree/ft_btree.h"
# include "char/char.h"
# include "list/ft_list.h"
# include "math/math.h"
# include "printf/ft_printf.h"
# include "str/ft_str.h"
# include "vector/vector.h"
# include "files/ft_files.h"
# include "tree/ft_tree.h"
# include <stdlib.h>
# include <unistd.h>

typedef int	(*t_comp) (void *, void *);

/**
 * @brief Sets `n` bytes of `ptr` to `c`.
 * @param ptr A pointer to a memory area.
 * @param c A byte.
 * @param n The ammount of bytes to set to `c`.
 * @return The `ptr` pointer.
 */
void	*ft_memset(void *ptr, int c, size_t n);

/**
 * @brief Writes `n` zeros ('\0') to `ptr`.
 * @param ptr A pointer to a memory area.
 * @param n The ammount of bytes to set to zero.
 */
void	ft_bzero(void *ptr, size_t n);

/*
 * @brief Copies `n` bytes of `src` to `dst`. The memory areas mus not overlap.
 * Use `ft_memmove` if the memory areas do overlap.
 * @param dst A pointer to a memory area.
 * @param src A pointer to a memory area.
 * @param n The ammount of bytes to copy.
 * @return The `dst` pointer.
 */
void	*ft_memcpy(void *dst, const void *src, size_t n);

void	*ft_grow(void *previous, size_t oldsize, size_t size);

/**
 * @brief copies `n` bytes from memory area `src` to memory area `dst`.
 * The memory areas may overlap: copying takes place as though the bytes in
 * `src` are first copied into a temporary array that does not overlap `src`
 * or `dst`, and the bytes are then copied from the temporary array to `dst`.
 * @param dst A pointer to a memory area.
 * @param src A pointer to a memory area.
 * @param n The ammount of bytes to copy.
 * @return The `dst` pointer.
 */
void	*ft_memmove(void *dst, const void *src, size_t n);

/**
 * @brief Returns a pointer to the first occurence of the byte `c` in `ptr` if
 * it exists, `NULL` otherwise.
 * @param ptr A memory area.
 * @param c A byte.
 * @return A pointer to the first occurence of the byte `c` in `ptr` if it
 * exists, `NULL` otherwise.
 */
void	*ft_memchr(const void *ptr, int c, size_t n);

/**
 * @brief Compares with the lexical order the `n` first bytes of `ptr_1`
 * and `ptr_2`.
 * @param ptr_1 A memory area.
 * @param ptr_2 A memory area.
 * @param n The max ammount of bytes to compare.
 * @return The lexical order of the two memory area.
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Allocates (with malloc(3)) and returns a string representing the
 * integer received as an argument. Negative numbers must be handled.
 * @param n The integer to convert.
 * @return The string representing the integer or `NULL` if the allocation
 * fails.
 */
char	*ft_itoa_base(int n, char *base);

/**
 * @brief Allocates (with malloc(3)) and returns a string representing the
 * unsigned integer received as an argument.
 * @param n The unsigned integer to convert.
 * @return The string representing the unsigned integer or `NULL` if 
 * the allocation fails.
 */
char	*ft_uitoa_base(unsigned int n, char *base);

char	*ft_ltoa_base(long nb, char *base);

char	*ft_ultoa_base(unsigned long nb, char *base);

/**
 * @brief Allocates (with malloc(3)) and returns a string representing the
 * integer received as an argument. Negative numbers must be handled.
 * @param n The integer to convert.
 * @return The string representing the integer or `NULL` if the allocation
 * fails.
 */
char	*ft_itoa(int n);

/**
 * @brief Allocates (with malloc(3)) and returns a string representing the
 * unsigned integer received as an argument.
 * @param n The unsigned integer to convert.
 * @return The string representing the unsigned integer or `NULL` if 
 * the allocation fails.
 */
char	*ft_uitoa(unsigned int n);

/**
 * @brief Converts the initial portion of the string pointed to by `str` to an
 * integer.
 * @param str The string to be converted.
 * @return The converted value.
 */
int		ft_atoi(const char *str);

/**
 * @brief Allocates memory for an array of `nmemb` elements of size bytes each
 * and returns a pointer to the allocated memory. The memory is set to zero.
 * If `nmemb` or `size` is 0, then calloc() returns either NULL, or a unique
 * pointer value that can later be successfully passed to free(). If the
 * multiplication of `nmemb` and `size` would result in integer overflow, then
 * calloc() returns `NULL` and sets `errno` to `EINOMEM`.
 * @param nmemb The number of elements if the array.
 * @param size The size in bytes of each element.
 * @return Return a pointer to the allocated memory or NULL if case of error.
 */
void	*ft_calloc(size_t nmemb, size_t size);

/******************************************************************************/
/*                                                                            */
/* IO                                                                         */
/*                                                                            */
/******************************************************************************/

/**
 * @brief Outputs the character `c` to the given file descriptor.
 * @param c The character to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs the string `str` to the given file descriptor.
 * @param str The string to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putstr_fd(char *str, int fd);

/**
 * @brief Outputs the string `str` to the given file descriptor followed by a
 * newline.
 * @param str
 * @param fd
 */
void	ft_putendl_fd(char *str, int fd);

/**
 * @brief Outputs the signed integer `n` to the given file descriptor.
 * @param n The integer to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putnbr_fd(signed int n, int fd);

/**
 * @brief Read a line from the given fd.
 * @param fd A file descriptor to read from.
 * @return A line red from the file descriptor.
 */
char	*get_next_line(int fd);

/**
 * @brief Returns the linear interpolation of a color a and a color b
 * at a certain step (between 0 and 100).
 * @param color1 The start color.
 * @param color2 The stop color.
 * @param step A value between 0 and 1
 */
int		ft_gradient(int color1, int color2, float step);

int		ft_color(int r, int g, int b);

/**
 * @brief Sort an array based on a comp function.
 * @param arr A pointer to an arr that need to be sorted.
 * @param size The size of the array.
 * @param cmp A pointer to a comparaison function.
 */
void	ft_quicksort(void **arr, int size, t_comp cmp);

void	ft_fail_malloc(void **ptr, void (*f)(void *));

/** ft_parse_args
 * @brief Returns a bit-representation of the flags defined in flagset and 
 * contained in str. If str contains one or more of flagset char, the returned 
 * value will have a toggled bit whose position depends on the binary position 
 * of its corresponding flag in the flagset.
 * ORDER OF THE FLAGS MATTERS, DO NOT CHANGE IT FROM A FUNCTION CALL TO ANOTHER.
 * @param `str` A flag-containing string
 * @param `flagset` A string containing and defining  every possible flags.
 * @return An integer with bytes reflecting the flags contained by flagset 
 * and found in str.
 */
int		ft_parse_args(char *str, char *flagset);

/**
 * @brief Returns 1 if the flaglist `flags` contains the flag `f`, or 0.
 * ORDER OF THE FLAGS MATTERS, DO NOT CHANGE IT FROM A FUNCTION CALL TO ANOTHER.
 * @param `flags` An integer representation of the flags.
 * @param `flagset` A list of flags.
 * @param `f` A flag that is or isn't contained by `flags`.
 */
int		ft_is_flagged(int flags, char *flagset, char f);

#endif
