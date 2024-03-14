/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 02:35:25 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/13 12:09:44 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tree/ft_tree.h"
#include "../libft.h"
#include "ft_files.h"
#include <dirent.h>
#include <errno.h>
#include <stdio.h>

static int	is_hidden(int flags)
{
	return (flags & F_HIDDEN);
}

static int	is_recursive(int flags)
{
	return (flags & F_RECURSIVE);
}

void	build_filename(char filename[256], char *path, char *name)
{
	ft_strlcpy(filename, path, 255);
	ft_strlcat(filename, "/", 255);
	ft_strlcat(filename, name, 255);
}

static void	add_file_to_tree(int flags, struct dirent *file, t_tree *files,
		char *path)
{
	t_tree			*child;
	char			filename[256];
	struct dirent	*dup;

	if (is_hidden(flags) || !(file->d_name[0] == '.'))
	{
		dup = malloc(sizeof(struct dirent));
		ft_memcpy(dup, file, sizeof(struct dirent));
		filename[0] = '\0';
		build_filename(filename, path, file->d_name);
		ft_strlcpy(dup->d_name, filename, 256);
		child = ft_treenew(dup);
		ft_treeadd_child(files, child);
		if (is_recursive(flags) && dup->d_type == DT_DIR && \
			ft_strcmp(dup->d_name, ".") != 0 && \
			ft_strcmp(dup->d_name, "..") != 0)
		{
			ft_readdir(&child, dup->d_name, flags);
		}
	}
}

void	ft_readdir(t_tree **head, char *path, int flags)
{
	DIR				*current_dir;
	struct dirent	*file;
	struct dirent	*filecopy;

	current_dir = opendir(path);
	if (current_dir == 0)
		return ;
	file = readdir(current_dir);
	if (*head == NULL)
	{
		filecopy = ft_calloc(1, sizeof(struct dirent));
		ft_memcpy(filecopy, file, sizeof(struct dirent));
		*head = ft_treenew(filecopy);
	}
	while (file)
	{
		add_file_to_tree(flags, file, *head, path);
		file = readdir(current_dir);
	}
	closedir(current_dir);
}
