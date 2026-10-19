/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-barh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 16:54:06 by ael-barh          #+#    #+#             */
/*   Updated: 2026/08/01 16:54:09 by ael-barh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	count;
	int	*ptr;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	count = max - min;
	ptr = (int *)malloc(sizeof(int) * count);
	if (ptr == NULL)
	{
		*range = NULL;
		return (-1);
	}
	i = 0;
	while (i < count)
	{
		ptr[i] = min + i;
		i++;
	}
	*range = ptr;
	return (count);
}
