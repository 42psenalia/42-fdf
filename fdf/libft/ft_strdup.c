/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:32:28 by psenalia          #+#    #+#             */
/*   Updated: 2024/02/26 15:23:48 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	len;

	len = (ft_strlen(s)) + 1;
	dst = (char *)malloc(sizeof(char) * len);
	if (!(dst))
		return (NULL);
	else
		ft_strlcpy(dst, s, len);
	return (dst);
}
