/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:11:18 by lribette          #+#    #+#             */
/*   Updated: 2024/03/23 06:14:25 by aboyreau         ###   ########.fr       */
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
	printf("\x1b[38;2;150;0;0;1m%s\n\e[0m", str);
	exit(EXIT_FAILURE);
}

void	check_attrs(int argc, char **argv)
{
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
}

t_game	*parse(char **argv)
{
	int		fd;
	t_game	*game;

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
	close(fd);
	return (game);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*window;
	t_game	*game;

	check_attrs(argc, argv);
	game = parse(argv);
	if (game == NULL)
	{
		ft_dprintf(2, "Game initialization failed\n");
		return (1);
	}
	mlx = mlx_init();
	window = mlx_new_window(mlx, WIDTH, HEIGHT, "2D2R");
	game->texture->mlx = mlx;
	game->texture->window = window;
	if (window == NULL)
		return (exit_error("Couldn't create the window\n", game), EXIT_FAILURE);
	// mlx_mouse_hide(mlx, window); // ça leak à mort
	init_keybindings(mlx, window, game);
	mlx_loop_hook(mlx, (void *)render, (void *[]){mlx, window, (void *)game});
	mlx_loop(mlx);
	mlx_clear_window(mlx, window);
	mlx_destroy_window(mlx, window);
	mlx_destroy_display(mlx);
	free(mlx);
	free_game(game);
}
