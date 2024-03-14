/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:11:18 by lribette          #+#    #+#             */
/*   Updated: 2024/03/14 11:10:16 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include "str/ft_str.h"
#include <unistd.h>

// int	main(int argc, char **argv)
// {
// 	if (argc != 2)
// 	{
// 		ft_dprintf(STDERR_FILENO, "Usage: ./cub3d <map.cub>\n");
// 		exit(1);
// 	}
// 	if (!ft_strendswith(argv[1], ".cub"))
// 	{
// 		ft_dprintf(STDERR_FILENO, "Wrong file extension.\n");
// 		exit(1);
// 	}
/*   Updated: 2024/03/14 10:55:37 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	(void)argc;
	t_game	game;

	game.map = NULL;
	int fd = open(argv[1], O_RDONLY);
	parse_map(fd, &game);
}
