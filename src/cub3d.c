/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:11:18 by lribette          #+#    #+#             */
/*   Updated: 2024/03/27 15:57:40 by lribette         ###   ########.fr       */
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
	printf("%s%s%s", RED, str, RESET);
	exit(EXIT_FAILURE);
}

void	check_attrs(int argc, char **argv)
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

void	free_mlx(t_textures *texture)
{
		// mlx_destroy_image(texture->mlx, texture->wall[i]);
	// free_table(texture->wall);
	mlx_destroy_image(texture->mlx, texture->game);
	mlx_destroy_image(texture->mlx, texture->map);
	mlx_clear_window(texture->mlx, texture->window);
	mlx_destroy_window(texture->mlx, texture->window);
	mlx_destroy_display(texture->mlx);
	free(texture->mlx);
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
	game->texture->mlx = mlx_init();
	game->texture->window = mlx_new_window(game->texture->mlx, WIDTH, HEIGHT, "2D2R");
	if (game->texture->window == NULL)
		return (exit_error("Couldn't create the window\n", game), EXIT_FAILURE);
	for (int i = 0; i < 4; i++)
	{
		game->texture->wall[i] = load_texture(game->texture->mlx, game->texture->wall[i]);
		if (game->texture->wall[i] == NULL)
		{
			free_mlx(game->texture);
			// free_mlx(game->texture->mlx, game->texture->window);
			free_game(game);
			return (42);
		}
	}
	init_keybindings(game->texture->mlx, game->texture->window, (void *[]){game, NULL, NULL, &redraw});
	game->texture->game = mlx_new_image(game->texture->mlx, WIDTH, HEIGHT);
	game->texture->map = mlx_new_image(game->texture->mlx, (game->longest_line + 1) * SCALE_FACTOR, (ft_tablen(game->map)) * SCALE_FACTOR);
	mlx_loop_hook(game->texture->mlx, (void *)render, (void *[]){game->texture->mlx, game->texture->window, (void *)game,
		&redraw});
	mlx_loop(game->texture->mlx);
	free_mlx(game->texture);
	// free_mlx(game->texture->mlx, game->texture->window);
	free_game(game);
}
