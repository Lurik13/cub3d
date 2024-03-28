/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:11:18 by lribette          #+#    #+#             */
/*   Updated: 2024/03/28 11:08:58 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "cub3d.h"
#include "mlx.h"
#include "printf/ft_printf.h"
#include "render.h"
#include "str/ft_str.h"
#include <stdlib.h>
#include <unistd.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	t_data	img_data;

	img_data.img = data;
	img_data.addr = mlx_get_data_addr(data, &img_data.bits_per_pixel,
			&img_data.line_length, &img_data.endian);
	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
	{
		dst = img_data.addr + (y * img_data.line_length + x
				* (img_data.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	exit_error(char *str, t_game *game)
{
	free_game(game, 0);
	printf("%s%s%s", RED, str, RESET);
	exit(EXIT_FAILURE);
}

void	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_dprintf(STDERR_FILENO, "%sUsage: ./cub3d <map.cub>%s", RED, RESET);
		exit(EXIT_FAILURE);
	}
	if (!ft_strendswith(argv[1], ".cub"))
	{
		ft_dprintf(STDERR_FILENO, "%sWrong file extension.%s", RED, RESET);
		exit(EXIT_FAILURE);
	}
}

t_game	*parse(char **argv)
{
	int		fd;
	t_game	*game;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}
	game = init_game();
	if (game == NULL)
	{
		ft_dprintf(2, "Map initialization failed !\n");
		exit(EXIT_FAILURE);
	}
	if (parse_attrs(fd, &game))
	{
		ft_dprintf(2, "Malformed map attributes\n");
		free_game(game, 0);
		exit(EXIT_FAILURE);
	}
	parse_map(fd, game);
	close(fd);
	return (game);
}

int	load_texture(t_game *game)
{
	int		index;
	int		exit_code;
	char	*path;

	exit_code = 0;
	for (int i = 0; i < 4; i++)
	{
		path = game->texture->wall[i];
		game->texture->wall[i] = mlx_xpm_file_to_image(game->texture->mlx, path, &index, &index);
		if (game->texture->wall[i] == NULL)
		{
			ft_dprintf(STDERR_FILENO, "Cannot load the texture %s\n", path);
			exit_code = 42;
		}
		free(path);
	}
	return (exit_code);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	long	redraw;

	redraw = 1;
	check_args(argc, argv);
	game = parse(argv);
	if (game == NULL)
	{
		ft_dprintf(2, "Game initialization failed\n");
		return (1);
	}
	game->texture->mlx = mlx_init();
	if (load_texture(game))
	{
		free_game(game, 1);
		return (1);
	}
	game->texture->window = mlx_new_window(game->texture->mlx, WIDTH, HEIGHT, "2D2R");
	if (game->texture->window == NULL)
		return (exit_error("Couldn't create the window\n", game), EXIT_FAILURE);
	init_keybindings(game->texture->mlx, game->texture->window, (void *[]){game, NULL, NULL, &redraw});
	game->texture->game = mlx_new_image(game->texture->mlx, WIDTH, HEIGHT);
	game->texture->map = mlx_new_image(game->texture->mlx, (game->longest_line + 1) * SCALE_FACTOR, (ft_tablen(game->map)) * SCALE_FACTOR);
	mlx_loop_hook(game->texture->mlx, (void *)render, (void *[]){game->texture->mlx, game->texture->window, (void *)game,
		&redraw});
	mlx_loop(game->texture->mlx);
	free_game(game, 1);
}
