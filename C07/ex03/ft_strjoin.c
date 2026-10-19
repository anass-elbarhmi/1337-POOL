/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-barh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 16:47:25 by ael-barh          #+#    #+#             */
/*   Updated: 2026/08/01 16:47:31 by ael-barh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strs_len(char **strs, int size)
{
	int	i;
	int	j;
	int	strs_len;

	i = 0;
	strs_len = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i] && strs[i][j])
		{
			strs_len++;
			j++;
		}
		i++;
	}
	return (strs_len);
}

int	ft_str_len(char *str)
{
	int	str_len;

	if (!str)
		return (0);
	str_len = 0;
	while (str[str_len])
		str_len++;
	return (str_len);
}

int	ft_strcpy_pos(char *dest, char *src, int pos)
{
	int	j;

	if (!src)
		return (pos);
	j = 0;
	while (src[j])
	{
		dest[pos] = src[j];
		pos++;
		j++;
	}
	return (pos);
}

char	*ft_empty_string(void)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[0] = '\0';
	return (ptr);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ptr;
	int		f_len;
	int		i;
	int		ptr_pos;

	if (size <= 0 || !strs)
		return (ft_empty_string());
	f_len = ft_strs_len(strs, size) + (ft_str_len(sep) * (size - 1));
	ptr = (char *)malloc(sizeof(char) * (f_len + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	ptr_pos = 0;
	while (i < size)
	{
		ptr_pos = ft_strcpy_pos(ptr, strs[i], ptr_pos);
		i++;
		if (i != size)
			ptr_pos = ft_strcpy_pos(ptr, sep, ptr_pos);
	}
	ptr[ptr_pos] = '\0';
	return (ptr);
}
