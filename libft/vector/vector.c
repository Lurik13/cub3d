/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 04:41:38 by atu               #+#    #+#             */
/*   Updated: 2024/01/08 06:21:52 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "vector.h"
#include <math.h>

t_3dvector	new_3dv(t_3dpoint p1, t_3dpoint p2)
{
	t_3dvector	vector;

	vector.points[0] = p1;
	vector.points[1] = p2;
	vector.h = p2.h - p1.h;
	vector.v = p2.v - p1.v;
	vector.d = p2.d - p1.d;
	return (vector);
}

t_3dpoint	new_3dp(double h, double v, double d)
{
	t_3dpoint	point;

	point.d = d;
	point.h = h;
	point.v = v;
	return (point);
}

t_2dvector	new_2dv(t_2dpoint p1, t_2dpoint p2)
{
	t_2dvector	vector;

	vector.points[0] = p1;
	vector.points[1] = p2;
	vector.h = p2.h - p1.h;
	vector.v = p2.v - p1.v;
	return (vector);
}

t_2dpoint	new_2dp(double h, double v)
{
	t_2dpoint	point;

	point.v = v;
	point.h = h;
	return (point);
}
