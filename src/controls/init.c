/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 09:35:51 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/22 11:05:15 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "controls.h"

void	init_keybindings(void *mlx, void *window, t_game *game)
{
	void	**args;

	args = ft_calloc(3, sizeof(void *));
	args[0] = game;
	args[1] = mlx;
	args[2] = window;
	mlx_hook(window, 2, 1L << 0, (void *)move, (void *)game);
	mlx_hook(window, 6, 1L << 6, (void *)mouse_rotate, args);
}
