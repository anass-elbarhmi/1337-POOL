/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-barh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 20:14:49 by ael-barh          #+#    #+#             */
/*   Updated: 2026/07/26 20:15:02 by ael-barh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	ascii[256];

	i = 0;
	while (i < 256)
	{
		ascii[i] = 0;
		i++;
	}
	if (base[0] == '\0' || ft_strlen(base) == 1)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (ascii[(unsigned char)base[i]] == 0)
			ascii[(unsigned char)base[i]]++;
		else
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nb, char *base)
{
	long	lnb;
	int		b;
	char	c;

	if (check_base(base) == 0)
		return ;
	b = ft_strlen(base);
	lnb = nb;
	if (lnb < 0)
	{
		write(1, "-", 1);
		lnb = -lnb;
	}
	if (lnb / b != 0)
		ft_putnbr_base(lnb / b, base);
	c = base[lnb % b];
	write(1, &c, 1);
}
