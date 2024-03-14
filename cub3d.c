/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:11:18 by lribette          #+#    #+#             */
/*   Updated: 2024/03/14 12:50:08 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mlx.h"
#include "printf/ft_printf.h"
#include "str/ft_str.h"
#include "cub3d.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_game	*game;
	void	*mlx;

	if (argc != 2)
	{
		ft_dprintf(STDERR_FILENO, "Usage: ./cub3d <map.cub>\n");
		exit(1);
	}
	if (!ft_strendswith(argv[1], ".cub"))
	{
		ft_dprintf(STDERR_FILENO, "Wrong file extension.\n");
		exit(1);
	}
	game = init_game();
	mlx = mlx_init();
	fd = open(argv[1], O_RDONLY);
	if (parse_attrs(mlx, fd, &game))
		exit(1);
	// free_game(mlx, game);
}
