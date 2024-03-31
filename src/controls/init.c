/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 09:35:51 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/31 15:26:26 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "controls.h"

int	mlx_close(int keycode, void *mlx)
{
	if (keycode != 65307)
		return (-1);
	mlx_loop_end(mlx);
	return (0);
}

int	mlx_close_cross(void *mlx_ptr)
{
	return (mlx_close(65307, mlx_ptr));
}

void	init_keybindings(void *mlx, void *window, void **args)
{
	mlx_hook(window, 2, 1L << 0, (void *)move, args);
	mlx_hook(window, 6, 1L << 6, (void *)mouse_rotate, args);
	mlx_hook(window, 33, (1L << 17), mlx_close_cross, mlx);
}

int	verif_wall(char **map, double move, double pos_v, double pos_h)
{
	if (move < 0)
	{
		move -= 0.00000000001;
		if (map[(int)(pos_v - move)][(int)(pos_h - move)] == '1')
			return (EXIT_FAILURE);
	}
	else
	{
		move += 0.00000000001;
		if (map[(int)(pos_v + move)][(int)(pos_h + move)] == '1')
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
