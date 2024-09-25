/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transcriptor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:25:33 by psenalia          #+#    #+#             */
/*   Updated: 2024/09/24 19:02:24 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	getinput(char *argv, t_fdf *processor)
{
	char			*linerow;
	char			**columns;
	unsigned int	tempcol;
	unsigned int	temprow;

	processor->fd = (argv, O_RDONLY);
	if (!processor->fd)
		return (perror("Cannot open file "));
	temprow = 0;
	linerow = get_next_line(processor->fd);
	while (linerow)
	{
		columns = ft_split(linerow, 32);
		tempcol = getcol(columns);
		if (processor->col && tempcol != processor->col)
			return (apoptosis(processor, columns, linerow));
		else if (!processor->col)
			processor->col = tempcol;
		temprow++;
		get_next_line(processor->fd);
	}
	processor->row = temprow;
	close(processor->fd);
}
