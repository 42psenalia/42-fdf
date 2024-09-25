/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:16:36 by psenalia          #+#    #+#             */
/*   Updated: 2024/09/24 18:19:17 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool	checkfile(char *argv)
{
	int		i;
	size_t	n;

	if (!ft_strnstr(argv, ".fdf", ft_strlen(argv)))
		return (false);
	i = 0;
	while (argv[i])
	{
		if (argv[i] == 32 || argv[i] == 9)
			n++;
		i++;
	}
	if (ft_strlen(argv) != n)
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_fdf	processor;

	if (argc != 2)
		return (write(2, "Error: Please input 1 map file\n", 32));
	if (!checkfile(argv[1]))
		return (write(2, "Error: File incorrect/unrecognizable\n", 38));
	getinput(argv[1], &processor);
}
