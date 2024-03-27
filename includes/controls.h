/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 09:25:45 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/27 15:15:50 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

# define LEFT_KEY 97
# define RIGHT_KEY 100
# define DOWN_KEY 115
# define UP_KEY 119
# define LEFT_ARROW_KEY 65361
# define RIGHT_ARROW_KEY 65363
# define ESCAPE_KEY 65307
# define MOVEMENT 0.06570
# define ROTATION_SPEED 0.1

void	move(int keycode, void *data);
void	mouse_rotate(int x, int y, void *param);
int		mlx_close(int keycode, void *mlx);
void	init_keybindings(void *mlx, void *window, void **args);

#endif
