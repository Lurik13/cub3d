/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 09:35:51 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/18 06:35:41 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "controls.h"

void	init_keybindings(void *window, t_game *game)
{
	mlx_hook(window, 2, 1L << 0, (void *)move, (void *)game);
}
