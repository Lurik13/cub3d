/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:11:18 by lribette          #+#    #+#             */
/*   Updated: 2024/03/31 15:21:30 by aboyreau         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_game	*game;
	long	redraw;

	redraw = 1;
	check_args(argc, argv);
	game = parse(argv);
	if (game == NULL)
		exit_error("Game initialization failed\n", NULL);
	game->texture->mlx = mlx_init();
	if (load_texture(game))
	{
		free_game(game, 1);
		return (1);
	}
	game->texture->window = mlx_new_window(game->texture->mlx,
			WIDTH, HEIGHT, "2D2R");
	if (game->texture->window == NULL)
		exit_error("Couldn't create the window\n", game);
	run_game(game, &redraw);
	free_game(game, 1);
}
