/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:11:18 by lribette          #+#    #+#             */
/*   Updated: 2024/03/26 09:30:20 by atu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "cub3d.h"
#include "mlx.h"
// #include "mlx_int.h"
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

void	free_mlx(void *mlx, void *window)
{
	mlx_clear_window(mlx, window);
	mlx_destroy_window(mlx, window);
	mlx_destroy_display(mlx);
	free(mlx);
}

void	*load_texture(void *mlx, char *path)
{
	int		index;
	void	*texture;

	texture = mlx_xpm_file_to_image(mlx, path, &index, &index);
	if (texture == NULL)
		ft_dprintf(STDERR_FILENO, "Cannot load the texture %s\n", path);
	free(path);
	return (texture);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*window;
	t_game	*game;
	long	redraw;

	redraw = 1;
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
	for (int i = 0; i < 4; i++)
	{
		game->texture->wall[i] = load_texture(mlx, game->texture->wall[i]);
		if (game->texture->wall[i] == NULL)
		{
			free_mlx(mlx, window);
			free_game(game);
			return (42);
		}
	}
	init_keybindings(mlx, window, (void *[]){game, mlx, window, &redraw});
	game->texture->game = mlx_new_image(mlx, WIDTH, HEIGHT);
	game->texture->map = mlx_new_image(mlx, (game->longest_line + 1) * SCALE_FACTOR, (ft_tablen(game->map)) * SCALE_FACTOR);
	mlx_loop_hook(mlx, (void *)render, (void *[]){mlx, window, (void *)game,
		&redraw});
	mlx_loop(mlx);
	free_mlx(mlx, window);
	free_game(game);
}
