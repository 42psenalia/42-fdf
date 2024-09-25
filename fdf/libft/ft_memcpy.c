/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:31:23 by psenalia          #+#    #+#             */
/*   Updated: 2024/03/09 13:22:12 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*finpoint;

	finpoint = dest;
	if (!dest && !src)
		return (dest);
	while (n--)
		*(unsigned char *)(dest + n) = *(unsigned char *)(src + n);
	return (finpoint);
}
