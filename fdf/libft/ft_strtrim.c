/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:37:40 by psenalia          #+#    #+#             */
/*   Updated: 2024/03/18 12:56:29 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	primer(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	init;
	size_t	term;
	size_t	len;

	init = 0;
	while (s1[init] && primer(s1[init], set))
		init++;
	term = ft_strlen(s1);
	while (term > init && primer(s1[term - 1], set))
		term--;
	trimmed = (char *)malloc(sizeof(char) * (term - init +1));
	if (!trimmed)
		return (NULL);
	len = 0;
	while (init + len < term)
	{
		trimmed[len] = s1[init + len];
		len++;
	}
	trimmed[len] = '\0';
	return (trimmed);
}
