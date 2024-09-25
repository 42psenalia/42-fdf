/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:20:30 by psenalia          #+#    #+#             */
/*   Updated: 2024/03/09 17:56:30 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	else if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		len += 2;
		n *= -1;
	}
	else
		len++;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	bs_int(char *nbr, int n)
{
	if (n == -2147483648)
	{
		nbr[0] = '-';
		nbr[1] = '2';
	}
}

char	*ft_itoa(int n)
{
	char	*nbr;
	int		len;

	len = intlen(n);
	nbr = (char *)malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (NULL);
	nbr[len] = '\0';
	bs_int(nbr, n);
	if (n == -2147483648)
		n = 147483648;
	if (n == 0)
		nbr[len - 1] = 48;
	if (n < 0)
	{
		*nbr = '-';
		n *= -1;
	}
	while (len-- && n > 0)
	{
		nbr[len] = (n % 10) + 48;
		n /= 10;
	}
	return (nbr);
}
