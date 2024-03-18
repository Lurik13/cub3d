/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:11:18 by lribette          #+#    #+#             */
/*   Updated: 2024/03/18 13:14:37 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "mlx.h"
#include "printf/ft_printf.h"
#include "render.h"
#include "str/ft_str.h"
#include "cub3d.h"
#include "controls.h"

void	exit_error(char *str, t_game *game)
{
	free_game(game);
	free_table(game->map);
	printf("\x1b[38;2;150;0;0;1m%s\n\e[0m", str);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	*game;
	void	*mlx;
	void	*window;

	if (argc != 2)
	{
		ft_dprintf(STDERR_FILENO, "Usage: ./cub3d <map.cub>\n");
		exit(EXIT_FAILURE);
	}
	if (!ft_strendswith(argv[1], ".cub"))
	{
		ft_dprintf(STDERR_FILENO, "Wrong file extension.\n");
		exit(EXIT_FAILURE);
	}
	game = init_game();
	if (game == NULL)
	{
		ft_dprintf(2, "Map initialization failed !\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror(argv[1]);
		free_game(game);
		exit(EXIT_FAILURE);
	}
	if (parse_attrs(fd, &game))
	{
		ft_dprintf(2, "Malformed map attributes\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
	parse_map(fd, game);
	mlx = mlx_init();
	window = mlx_new_window(mlx, WIDTH, HEIGHT, "2D2R");
	game->texture->mlx = mlx;
	game->texture->window = window;
	if (window == NULL)
		return (exit_error("Couldn't create the window\n", game), EXIT_FAILURE);
	init_keybindings(window, game);
	mlx_loop_hook(mlx, (void *)render, (void *[]){mlx, window, (void *)game});
	mlx_loop(mlx);
	mlx_destroy_window(mlx, window);
	free_game(game);
}
