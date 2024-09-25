/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:08:47 by psenalia          #+#    #+#             */
/*   Updated: 2024/03/07 18:06:23 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	size_t	sub;

	sub = nmemb * size;
	if (sub > UINT_MAX)
		return (NULL);
	else if (sub < nmemb && sub < size)
		return (NULL);
	array = malloc(sub);
	if (!array)
		return (NULL);
	ft_bzero(array, sub);
	return (array);
}
