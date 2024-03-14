/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 02:36:04 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/14 06:20:27 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILES_H
# define FT_FILES_H

# include "../tree/ft_tree.h"
# include <dirent.h>

# define F_HIDDEN 1
# define F_RECURSIVE 2

void	ft_readdir(t_tree **head, char *path, int flags);

#endif
