/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-barh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 20:27:27 by ael-barh          #+#    #+#             */
/*   Updated: 2026/07/22 20:27:42 by ael-barh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	p_pos;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{
		j = 0;
		p_pos = i;
		while (to_find[j] && str[i] == to_find[j])
		{
			i++;
			j++;
		}
		if (to_find[j] == '\0')
			return (&str[p_pos]);
		i = p_pos + 1;
	}
	return (0);
}
