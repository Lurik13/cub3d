/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 02:16:04 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/18 09:45:07 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

/**
 * @brief Return the minimal value sent received in parameters.
 * @param a A float value.
 * @param b A float value.
 * @return The smallest value received as parameter.
 */
float	ft_min(float a, float b);

/**
 * @brief Return the maximal value sent received in parameters.
 * @param a A float value.
 * @param b A float value.
 * @return The greatest value received as parameter.
 */
float	ft_max(float a, float b);

/**
 * @brief Elevate a to the power of b.
 * @param a The base.
 * @param b The exponent.
 * @return `a` elevated to the power of `b`.
 */
int		ft_power(int a, int b);

/**
 * @brief Finds the absolute value of `a`.
 * @param a An integer.
 * @return Returns the absolute of `a`.
 */
double	ft_abs(double a);

/**
 * @brief Computes the length of ac according to pythagoras formula.
 * @param `ab` The first side of the triangle.
 * @param `bc` The second side of the triangle.
 * @return The length of the hypothenus of the triangle.
 */
double	ft_pythagoras(double ab, double bc);

#endif
