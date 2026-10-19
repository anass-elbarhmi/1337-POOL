/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-barh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 12:39:54 by ael-barh          #+#    #+#             */
/*   Updated: 2026/07/20 12:40:42 by ael-barh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_to_hex(int n)
{
	char	c;

	if (n < 10)
		c = n + '0';
	else
		c = 'a' + (n - 10);
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	char	backslash;

	backslash = '\\';
	while (*str)
	{
		if (!(*str >= 32 && *str <= 126))
		{
			write(1, &backslash, 1);
			put_to_hex(*str / 16);
			put_to_hex(*str % 16);
		}
		else
		{
			write(1, str, 1);
		}
		str++;
	}
}
