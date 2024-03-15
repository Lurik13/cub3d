/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 08:14:56 by atu               #+#    #+#             */
/*   Updated: 2024/03/15 05:52:44 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# define HEX_BASE_MAJ "0123456789ABCDEF"
# define HEX_BASE_MIN "0123456789abcdef"

typedef struct s_flags
{
	int	padding;
}				t_flags;

int		ft_printf(const char *str, ...);
int		ft_dprintf(int fd, const char *str, ...);
int		ft_vdprintf(int fd, const char *str, va_list lst);
int		ft_sprintf(char *buf, const char *str, ...);
int		ft_vsprintf(char *buf, const char *str, va_list lst);
char	*format_str(const char **str, va_list lst);
char	*h_int(va_list args);
char	*h_uint(va_list args);
char	*h_percent(__attribute__((unused)) va_list arg);
char	*h_void(__attribute__((unused)) va_list arg);
char	*h_pointer(va_list args);
char	*h_hex_min(va_list args);
char	*h_hex_maj(va_list args);
char	*h_char(va_list args);
char	*h_string(va_list args);
t_flags	parse_flags(const char **str);
char	*add_padding(char *str, t_flags flags);

#endif
