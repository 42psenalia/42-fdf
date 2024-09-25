/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:21:54 by psenalia          #+#    #+#             */
/*   Updated: 2024/03/07 15:55:19 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	finlen;

	if ((!dst || !src) && !size)
		return (0);
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen < size)
		finlen = dstlen + srclen;
	else
		return (size + srclen);
	srclen = 0;
	while (src[srclen] && (dstlen + 1) < size)
	{
		dst[dstlen] = src[srclen];
		dstlen++;
		srclen++;
	}
	dst[dstlen] = '\0';
	return (finlen);
}
