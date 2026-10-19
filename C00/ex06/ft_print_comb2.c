/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-barh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 11:53:54 by ael-barh          #+#    #+#             */
/*   Updated: 2026/07/16 17:41:51 by ael-barh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_2_digits(int num)
{
	char	digit1;
	char	digit2;

	digit1 = (num / 10) + '0';
	digit2 = (num % 10) + '0';
	write(1, &digit1, 1);
	write(1, &digit2, 1);
}

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;

	num1 = 0;
	while (num1 <= 98)
	{
		num2 = num1 + 1;
		while (num2 <= 99)
		{
			put_2_digits(num1);
			write(1, " ", 1);
			put_2_digits(num2);
			if (!(num1 == 98 && num2 == 99))
			{
				write(1, ", ", 2);
			}
			num2++;
		}
		num1++;
	}
}
