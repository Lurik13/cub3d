/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fail_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 07:55:30 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/10 07:58:27 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <errno.h>

void	ft_fail_malloc(void **ptr, void (*f)(void *))
{
	if (f)
		f(*ptr);
	else
		free(*ptr);
	*ptr = NULL;
	errno = ENOMEM;
}
