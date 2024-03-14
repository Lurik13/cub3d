/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 02:14:34 by aboyreau          #+#    #+#             */
/*   Updated: 2024/01/18 03:55:12 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_H
# define CHAR_H

/**
 * @brief Tells wether or not `c` is a letter.
 * @param c A character.
 * @return Wether or not `c` is a letter.
 */
int	ft_isalpha(int c);

/**
 * @brief Tells wether or not `c` is a digit.
 * @param c A character.
 * @return Wether or not `c` is a digit.
 */
int	ft_isdigit(int c);

/**
 * @brief Tells wether or not `c` is a letter or a digit.
 * @param c A character.
 * @return Wether or not `c` is a letter or a digit.
 */
int	ft_isalnum(int c);

/**
 * @brief Tells wether or not `c` is an ascii character.
 * @param c A character.
 * @return Wether or not `c` is an ascii character.
 */
int	ft_isascii(int c);

/**
 * @brief Tells wether or not `c` is printable.
 * @param c A character.
 * @return Wether or not `c` is printable.
 */
int	ft_isprint(int c);

/**
 * @brief If `c` is a letter, converts it to uppercase.
 * @param c a character.
 * @return The transformes character.
 */
int	ft_toupper(int c);

/**
 * @brief If `c` is a letter, converts it to lowercase.
 * @param c a character.
 * @return The transformes character.
 */
int	ft_tolower(int c);

#endif
