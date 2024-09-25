/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:33:29 by psenalia          #+#    #+#             */
/*   Updated: 2024/03/19 13:04:42 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*sub;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (size + 1 - start < len)
		len = size - start;
	if (start > size)
	{
		len = 0;
		start = 0;
	}
	sub = (char *)malloc(sizeof(*s) * (len + 1));
	if (!sub)
		return (NULL);
	size = 0;
	while (s[start] && size < len)
	{
		sub[size] = s[start + size];
		size++;
	}
	sub[size] = '\0';
	return (sub);
}
