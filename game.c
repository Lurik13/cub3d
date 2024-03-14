/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:59:45 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/14 11:00:38 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

t_game	*init_game()
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	game->texture->ceiling = -1;
	game->texture->floor = -1;
	ft_bzero(game->texture->wall, 4 * sizeof(void *));
	ft_bzero(game->texture->door, 4 * sizeof(void *));
	return (game);
}
