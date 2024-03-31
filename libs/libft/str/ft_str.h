/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 07:42:32 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/31 16:13:51 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_H
# define FT_STR_H

# include <stdlib.h>

/**
 * @brief Copies `src` to `dst`. Takes the full `size` of `dst` and guarantee
 * to NUL-terminate the result (as long as `size` is larger than 0). Note that a
 * byte for the NUL should be included in `size`. Can only operate on true "C"
 * strings. `src` must be NUL-terminated. Copies up to `size - 1` characters
 * from `src` to `dst`, NUL-terminating the result.
 * @param dst A pointer to a memory area.
 * @param src A string.
 * @param size The length of the string `ft_strlcopy` tries to create.
 * @return The length of `src`.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief Concatenate `str` to `dst`. Takes the full `size` of `dst`
 * and guarantee to NUL-terminate the result (as long as there is at least one
 * byte free in `dst`). Note that a byte for the NUL should be included in
 * `size`. Can only operate on true “C” strings. This means that both `src`
 * and `dst` must be NUL-terminated. Appends the NUL-terminated string `src` to
 * the end of `dst`. It will append at most `size - ft_strlen(dst) - 1` bytes,
 * NUL-terminating the result.
 * @param dst A pointer to a memory area.
 * @param src A string.
 * @param size The length of the string `ft_strlcat` tries to create.
 * @return The initial length of `dst` plus the length of `src`.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief Returns a pointer to the first occurence of `c` in `str` if it exists,
 * `NULL` otherwise.
 * @param str A string.
 * @param c A character.
 * @return A pointer to the first occurence of `c` in `str` if it exists,
 * `NULL` otherwise.
 */

char	*ft_strchr(const char *str, int c);

/**
 * @brief Returns a pointer to the last occurence of `c` in `str` if it exists,
 * `NULL` otherwise.
 * @param str A string.
 * @param c A character.
 * @return A pointer to the last occurence of `c` in `str` if it exists,
 * `NULL` otherwise.
 */
char	*ft_strrchr(const char *str, int c);

/**
 * @brief Compares with the lexical order the `n` first characters of `str_1`
 * and `str_2`.
 * @param str_1 A string.
 * @param str_2 A string.
 * @param n The max ammount of characters to compare.
 * @return The lexical order of the two string.
 */
int		ft_strncmp(const char *str_1, const char *str_2, size_t n);
/**
 * @brief Calculates th length of `str`.
 * @param str A string.
 * @return The length of `str`.
 */
size_t	ft_strlen(const char *str);

/**
 * @brief Locates the first occurrence of the null-terminated string `little`
 * in the string `big`, where not more than `len` characters are searched.
 * Characters that appear after a ‘\0’ character are not searched.
 * @param big The string to be searched.
 * @param little The string to search.
 * @param len The size of the search.
 * @return (If `little` is an empty string,
	`big` is returned); if `little` occurs
 * nowhere in `big`, `NULL` is returned; otherwise a pointer to the first
 * character of the first occurrence of `little` is returned.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief Allocates (with malloc(3)) and returns a copy of `str`.
 * @param str A string.
 * @return A copy of `str`.
 */
char	*ft_strdup(const char *str);

/**
 * @brief Allocates (with malloc(3)) and returns a substring from the
 * string `str`. The substring begins at index `start` and is of maximum
 * size `len`.
 * @param str The string from which to create the substring.
 * @param start The start index of the substring in the string `str`.
 * @param len The maximum length of the substring.
 * @return The substring or `NULL` if the allocation fails.
 */
char	*ft_substr(char const *str, unsigned int start, size_t len);

/**
 * @brief Allocates (with malloc(3)) and returns a new string, which is the
 * result of the concatenation of each strings passed as parameters.
 * The list of string must be NULL terminated.
 * @param str_1 The prefix string.
 * @param str_2 The suffix string.
 * @return The new string or `NULL` if the allocation fails.
 */
char	*ft_strjoin(char const *str_1, ...);

/**
 * @brief Returns the index of `c` in `charset`.
 * @param c A char.
 * @param charset A string.
 * @return The index of the char `c` in the string `charset`.
 */
int		ft_indexof(char c, char *charset);

/**
 * @brief Allocates (with malloc(3)) and returns a copy of `str` with the
 * characters specified in `set` removed from the beginning and the end of the
 * string.
 * @param str The string to be split.
 * @param set The delimiter character.
 * @return The array of new strings resulting from the split or `NULL` if the
 * allocation fails.
 */
char	*ft_strtrim(char const *str, char const *set);

/**
 * @brief Allocates (with malloc(3)) and returns an array of strings obtained by
 * splitting `str` using the character `delim_char` as a delimiter.
 * The array must end with a `NULL` pointer.
 * @param str The string to be split.
 * @param delim_char The delimiter character.
 * @return The array of new strings resulting from the split or `NULL` if the
 * allocation fails.
 */
char	**ft_split(char const *str, char delim_char);

/**
 * @brief Allocates (with malloc(3)) and returns a new string, which is the
 * result of the concatenation of `str_1` and `str_2`, but the string will never
 * be longer than `size` char.
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @param size The maximum length of the new string.
 * @return The new string or `NULL` if the allocation fails.
 */
char	*ft_strnjoin(char const *s1, char const *s2, size_t size);

/**
 * @brief Applies the function `f` to each character of the string `str`, and
 * passing its index as first argument to create a new string (with malloc(3))
 * resulting from successive applications of `f`.
 * @param str The string on which to iterate.
 * @param f The function to apply to each character.
 * @return The string created from the successive applications of `f`. Returns
 * `NULL` if the allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Applies the function `f` on each character of the string `str`,
 * passing its index as first argument. Each character is passed by address
 * to `f` to be modified if necessary.
 * @param str The string on which to iterate.
 * @param f The function to apply to each character.
 */
void	ft_striteri(char *str, void (*f)(unsigned int, char *));

/**
 * @brief TODO
 * @param TODO
 * @param TODO
 */
char	*ft_strtok(char *str, const char *delim);

/**
 * @brief TODO
 * @param TODO
 * @param TODO
 */
int		ft_strcontains(const char *str, char c);

/** 
 * @brief This function will determine if str contains the char `c` or not.
 * @param str A string that may contain `c`.
 * @param c A char that may be contained by the string `str`.
 * @return Returns 1 if `str` contains `c`, or 0 otherwise.
 */
char	*ft_strreplace(char *str, char *pattern, char *replacement);

/**
 * @brief Join s1 and s2, but stop at the first char `c` contained in s2.
 * The returned string will never contains a char `c` if s1 does not contains
 * `c`.
 * @param s1 A string that will be joined.
 * @param s2 A second string that will be joined until it the char `c` is met.
 * @param c A char that will be used as an end marker in s2.
 * @return A string composed of s1, and a part of s2, until s2 is equals to `c`
 * or terminated.
 */
char	*ft_strcjoin(const char *s1, const char *s2, char c);

/**
 * @brief Compares 2 strings.
 * @param s1 A string to compare.
 * @param s2 Another string to compare.
 * @return 0 if the string matches, the ascii diff between the first unmatching
 * chars otherwise.
 */
int		ft_strcmp(const char *s1, const char *s2);

int		ft_strstartswith(char *str, char *start);
int		ft_strendswith(char *str, char *end);
int		ft_strcount(char c, char *str);

#endif
