/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 09:25:45 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/23 05:57:31 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

# define LEFT_KEY 97
# define RIGHT_KEY 100
# define DOWN_KEY 115
# define UP_KEY 119
# define MOVEMENT 0.125
# define ROTATION_SPEED 0.1

void	move(int keycode, t_game *game);
void	init_keybindings(void *mlx, void *window, t_game *game);
void	mouse_rotate(int x, int y, void *param);
int	mlx_close(int keycode, void *mlx);

#endif
