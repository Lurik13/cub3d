/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:52:56 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/15 12:32:34 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "mlx.h"
# include "cub3d.h"
# include "libft.h"

# define WIDTH 1280
# define HEIGHT 1024

void	render(void *mlx, t_game *game);

#endif
