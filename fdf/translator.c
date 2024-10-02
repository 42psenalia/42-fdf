#include "fdf.h"

static void pixelize(t_fdf *ref, int x, int y, long color)
{
	int	w;
	int	h;

	w = ref->img->width;
	h = ref->img->height;
	if ((x >= 0 && x < w) && (y >= 0 && y < h))
		mlx_put_pixel(ref->img, x, y, (color << 8) + 255);
}

static void construct(t_plot start, t_plot end, t_fdf *ref)
{
	t_plot	diff;
	t_plot	temp;
	float	xsct;
	float	ysct;
	int		row;

	diff.x = end.x - start.x;
	diff.y = end.y - start.y;
	if (ft_abs(diff.x) > ft_abs(diff.y))
		diff.z = ft_abs(diff.x);
	else
		diff.z = ft_abs(diff.y);
	xsct = diff.x / diff.z;
	ysct = diff.y / diff.z;
	row = 0;
	temp.x = start.x;
	temp.y = start.y;
	while (row < diff.z)
	{
		temp.x += xsct;
		temp.y += ysct;
		pixelize(ref, (temp.x + (float)(WIDTH / 2)) - \
			((float)(ref->col / 2) * CONVRATE) + 200, \
			(temp.y + (float)(HEIGHT / 2)) - \
			((float)(ref->row / 2) * CONVRATE), start.c);
		i++;
	}
}

void	drawgrid(t_fdf *processor)
{
	int	i;
	int	j;

	j = 0;
	while (j < processor->row)
	{
		i = 0;
		while (i < processor->col)
		{
			if (j < processor->row - 1)
				construct(processor->plot[i][j], processor->plot[i + 1][j], \
					processor);
			if (i < processor->col - 1)
				construct(processor->plot[i][j], processor->plot[i][j + 1], \
					processor);
			i++;
		}
		j++;
	}
}

void	translation(t_fdf *processor)
{
	int		i;
	int		j;
	float	prex;
	float	prey;

	j = 0;
	while (j < processor->row)
	{
		i = 0;
		while (i < processor->col)
		{
			prex = processor->plot[i][j].x;
			prey = processor->plot[i][j].y;
			processor->plot[i][j].x = (prex - prey) * 0.866;
			processor->plot[i][j].y = (prex + prey) * 0.5 \
				- processor->plot[i][j].z;
			i++;
		}
		j++;
	}
}