/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-barh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 10:28:24 by ael-barh          #+#    #+#             */
/*   Updated: 2026/07/18 10:41:49 by ael-barh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	to_right;
	int	to_left;

	to_right = 0;
	to_left = size - 1;
	while (to_right < to_left)
	{
		ft_swap(&tab[to_right], &tab[to_left]);
		to_right++;
		to_left--;
	}
}
