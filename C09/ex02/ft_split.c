/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-barh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 11:14:40 by ael-barh          #+#    #+#             */
/*   Updated: 2026/08/04 11:15:00 by ael-barh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_seperator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_seperator(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !is_seperator(str[i], charset))
			i++;
	}
	return (count);
}

char	*malloc_word(char *str, char *charset)
{
	int		len;
	int		i;
	char	*word;

	len = 0;
	i = 0;
	while (str[len] && !is_seperator(str[len], charset))
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	j = 0;
	split = (char **)malloc(sizeof(char *) * (count_word(str, charset) + 1));
	if (!split)
		return (NULL);
	while (str[i])
	{
		while (str[i] && is_seperator(str[i], charset))
			i++;
		if (str[i])
		{
			split[j] = malloc_word(&str[i], charset);
			j++;
			while (str[i] && !is_seperator(str[i], charset))
				i++;
		}
	}
	split[j] = NULL;
	return (split);
}
