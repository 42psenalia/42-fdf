/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:16:55 by psenalia          #+#    #+#             */
/*   Updated: 2024/03/04 13:45:05 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*strsave;
	size_t	len;

	strsave = ft_strdup(s);
	if (!strsave)
		return (NULL);
	len = 0;
	while (strsave[len])
	{
		strsave[len] = (*f)(len, strsave[len]);
		len++;
	}
	return (strsave);
}
