/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:58:22 by psenalia          #+#    #+#             */
/*   Updated: 2024/03/14 17:00:30 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	matching(const char *str, const char *findr, size_t start)
{
	int	at;

	at = 0;
	while (findr[at])
	{
		if (str[start] != findr[at])
			return (0);
		start++;
		at++;
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	count;
	size_t	litlen;
	int		match;

	if (!big && !len)
		return (NULL);
	if (big == little || little[0] == '\0')
		return ((char *)big);
	count = 0;
	litlen = ft_strlen(little) - 1;
	while (big[count] && len > count + litlen)
	{
		if (big[count] == little[0])
		{
			match = matching(big, little, count);
			if (match)
				return ((char *)big + count);
		}
		count++;
	}
	return (NULL);
}
