/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:42:01 by atu               #+#    #+#             */
/*   Updated: 2024/01/08 06:21:44 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_2dpoint
{
	double		h;
	double		v;
}				t_2dpoint;

typedef struct s_2dvector
{
	double		v;
	double		h;
	t_2dpoint	points[2];
}				t_2dvector;

typedef struct s_3dpoint
{
	double		v;
	double		h;
	double		d;
}				t_3dpoint;

typedef struct s_3dvector
{
	double		v;
	double		h;
	double		d;
	t_3dpoint	points[2];
}				t_3dvector;

t_3dvector		new_3dv(t_3dpoint p1, t_3dpoint p2);
t_3dpoint		new_3dp(double h, double v, double d);

t_2dvector		new_2dv(t_2dpoint p1, t_2dpoint p2);
t_2dpoint		new_2dp(double h, double v);

#endif
