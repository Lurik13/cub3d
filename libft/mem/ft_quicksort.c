/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:32:43 by atu               #+#    #+#             */
/*   Updated: 2024/02/06 00:13:16 by atu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

static void	swap(void **arr, int i, int j)
{
	void	*temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void	ft_quicksort(void **arr, int size, t_comp cmp)
{
	void	*pivot;
	int		i;
	int		j;

	if (size < 2)
		return ;
	i = 0;
	j = size - 1;
	pivot = arr[(i + j) / 2];
	while (i <= j)
	{
		if (cmp(arr[i], pivot) < 0)
			i++;
		else if (cmp(arr[i], pivot) >= 0 && cmp(arr[j], pivot) <= 0)
		{
			swap(arr, i, j);
			i++;
		}
		else
			j--;
	}
	ft_quicksort(arr, i, cmp);
	ft_quicksort(arr + i, size - i, cmp);
}
