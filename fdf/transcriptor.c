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

bool	getinput(char *argv, t_fdf *processor)
{
	char			*linerow;
	char			**columns;
	unsigned int	tempcol;
	unsigned int	temprow;

	processor->fd = (argv, O_RDONLY);
	if (!processor->fd)
		return (false);
	temprow = 0;
	linerow = get_next_line(processor->fd);
	while (linerow)
	{
		processor->content[temprow] = ft_strdup(linerow);
		columns = ft_split(linerow, 32);
		tempcol = getcol(columns);
		if (processor->col && tempcol != processor->col)
			apoptosis(processor, columns, linerow);
		else if (!processor->col)
			processor->col = tempcol;
		temprow++;
		get_next_line(processor->fd);
	}
	processor->row = temprow;
	close(processor->fd);
	return (true);
}

static void	plotmap(t_fdf *processor)
{
	char	**rowcontent;
	int		i;
	int		j;

	j = 0;
	while (j < processor->row)
	{
		rowcontent = ft_split(processor->content[j], 32);
		i = 0;
		while (i < processor->col)
		{
			processor->plot[i][j].x = (float)i * CONVRATE;
			processor->plot[i][j].y = (float)j * CONVRATE;
			if (rowcontent[i] != NULL)
			{
				checkoverflow(rowcontent[i])
				processor->plot[i][j].z = (float)ft_atoi(rowcontent[i]);
			}
			else
				processor->plot[i][j].z = 0;
			i++;
		}
		j++;
		freearray(rowcontent);
	}
}

static long	paint(char **color, t_fdf *processor, int i, int j)
{
	long	c;

	c = 0;
	if (color[1] != NULL)
		processor->plot[i][j].c = ft_atoh(color[1]);
	else
		processor->plot[i][j].c = WHITE_COLOR;
	c = processor->plot[i][j].c;
	return (c);
}

static void	colorize(t_fdf *processor)
{
	char	**rowcontent;
	char	**temp;
	int		i;
	int		j;

	j = 0;
	while (j < processor->row)
	{
		rowcontent = ft_split(processor->content[j], 32);
		i = 0;
		while (i < processor->col)
		{
			if (rowcontent[i] != NULL)
			{
				temp = ft_split(rowcontent[i], ',');
				processor->plot[i][j].c = paint(temp, processor, i, j);
				freearray(temp);
			}
			else
				processor->plot[i][j].c = WHITE_COLOR;
			i++;
		}
		freearray(rowcontent);
		j++;
	}
}

void	transcription(t_fdf *processor)
{
	plotmap(processor);
	colorize(processor);
}
