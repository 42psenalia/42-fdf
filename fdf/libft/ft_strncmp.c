/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:37:46 by psenalia          #+#    #+#             */
/*   Updated: 2024/03/14 11:44:57 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			length;
	unsigned char	cmp1;
	unsigned char	cmp2;

	if (n == 0)
		return (0);
	length = 0;
	while ((s1[length] != '\0' || s2[length] != '\0') && length < n)
	{
		if (s1[length] != s2[length])
		{
			cmp1 = s1[length];
			cmp2 = s2[length];
			return (cmp1 - cmp2);
		}
		length++;
	}
	return (0);
}
