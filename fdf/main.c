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
	n = 0;
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

static void	endprocess(t_fdf *processor)
{
	mlx_terminate(processor->mlx);
	freearray(processor->content);
	freegrid(processor->plot);
}

static void	ft_keyhook(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		endprocess(param);
}

int	main(int argc, char **argv)
{
	t_fdf	processor;

	if (argc != 2)
		return (write(2, "Error: Please input 1 map file\n", 32));
	if (!checkfile(argv[1]))
		return (write(2, "Error: File incorrect/unrecognizable\n", 38));
	processor = malloc(sizeof(t_fdf));
	if (!processor)
		return (write(2, "Error: malloc failed\n"));
	ft_bzero(&processor, sizeof(t_fdf));
	if (!getinput(argv[1], &processor))
		return (write(2, "Error: Cannot open file\n", 25));
	transcription(&processor);
	processor.mlx = mlx_init(WIDTH, HEIGHT, "FdF ", false);
	if (!processor.mlx)
		exit(EXIT_FAILURE);
	processor.img = mlx_new_image(processor.mlx, WIDTH, HEIGHT);
	translation(&processor);
	drawgrid(&processor);
	mlx_image_to_window(processor.mlx, processor.img, 0, 0);
	mlx_key_hook(processor.mlx, &ft_keyhook, &processor);
	mlx_loop(processor.mlx);
	endprocess(&processor);
	return (0);
}
