/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:45:52 by psenalia          #+#    #+#             */
/*   Updated: 2024/03/12 14:15:16 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	n_est(char const *s, char c)
{
	size_t			count;
	size_t			mark;
	unsigned int	len;

	count = 0;
	mark = 0;
	len = 0;
	while (s[len] || s[len] == '\0')
	{
		if (s[len] == c || s[len] == '\0')
		{
			if (len - mark > 0)
				count++;
			mark = len + 1;
		}
		if (s[len] == '\0')
			break ;
		len++;
	}
	return (count);
}

void	spliceset(char **set, char const *s, char c)
{
	size_t	len;
	size_t	mark;
	size_t	n;

	n = 0;
	len = 0;
	mark = 0;
	while (s[len] || s[len] == '\0')
	{
		if (s[len] == c || s[len] == '\0')
		{
			if (len - mark > 0)
			{
				set[n] = ft_substr(s, mark, (len - mark));
				n++;
			}
			mark = len + 1;
		}
		if (s[len] == '\0')
			break ;
		len++;
	}
	set[n] = NULL;
}

void	free_array(char **array, size_t n)
{
	while (n)
	{
		free(array[n]);
		n--;
	}
	free(array[n]);
	free(array);
}

char	**ft_split(char const *s, char c)
{
	char	**strset;
	size_t	n;
	size_t	i;

	if (!s)
		return (NULL);
	n = n_est(s, c);
	strset = (char **)malloc(sizeof(char *) * (n + 1));
	if (!strset)
		return (NULL);
	spliceset(strset, s, c);
	i = 0;
	while (strset[i])
	{
		if (!strset[i])
		{
			free_array(strset, n + 1);
			return (NULL);
		}
		i++;
	}
	return (strset);
}
