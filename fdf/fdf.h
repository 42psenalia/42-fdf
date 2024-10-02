/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:24:23 by psenalia          #+#    #+#             */
/*   Updated: 2024/09/24 18:19:13 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>
# include <MLX42/MLX42.h>
# include <unistd.h>
# include <math.h>
# include "libft.h"

# define WIDTH 1920
# define HEIGHT 1080
# define ANGLE 0.523599
# define ANGLE_120 2.09333333333
# define ANGLE_118 2.0597
# define ANGLE_122 2.1263
# define WHITE_COLOR 16777215
# define RED_COLOR 16711680
# define TYPE_FILE ".fdf"

typedef struct s_plot
{
	float			x;
	float			y;
	float			z;
	long			c;
}		t_plot;

typedef struct s_fdf
{
	int				fd;
	unsigned int	col;
	unsigned int	row;
	float		tmp_x;
	float		tmp_y;
	float		dx;
	float		dy;
	float		steps;
	float		ratio;
	char		**map;
	char		**tmp;
	t_plot		**plot;
	mlx_t		*mlx;
	mlx_image_t	*img;
}		t_fdf;

/*-----------------------------------------------------------------------------
 *				Input Handlers
 *---------------------------------------------------------------------------*/

// int		n_est(char const *s);
// long	ft_atol(const char *str);
// long	*mkrawset(char **argv, int size);
// int		splitandadd(char *s, long *inputset, int n);
// void	formstack(long *inputset, t_stack **stack, int size);
// t_stack	*find_latest(t_stack *stack);
// bool	setint(char const *argv);
// bool	numfault(char const *argv);
// bool	dupfault(long const *set, int size);
// bool	intexceed(long const *set, int size);

/*-----------------------------------------------------------------------------
 *				Essentials
 *---------------------------------------------------------------------------*/

// void	pushswap(t_stack **a, t_stack **b, int n);
// void	logic_q4radix(t_stack **a, t_stack **b);
// void	logic_q100(t_stack **a, t_stack **b);
// void	logic_q4st(t_stack **a, t_stack **b, int q4);
// void	partition(t_stack **a, t_stack **b, int q4);
// void	efficiency(t_stack **stack, int n);
// void	efficiency5(t_stack **a, t_stack **b, int n);
// bool	reprise(long *ideal, t_stack *a);

/*-----------------------------------------------------------------------------
 *				Commands
 *---------------------------------------------------------------------------*/

// void	sa(t_stack **a);
// void	sb(t_stack **b);
// void	ss(t_stack **a, t_stack **b);
// void	pa(t_stack **a, t_stack **b);
// void	pb(t_stack **a, t_stack **b);
// void	ra(t_stack **a);
// void	rb(t_stack **b);
// void	rr(t_stack **a, t_stack **b);
// void	rra(t_stack **a);
// void	rrb(t_stack **b);
// void	rrr(t_stack **a, t_stack **b);

/*-----------------------------------------------------------------------------
 *				Utilities
 *---------------------------------------------------------------------------*/

// long	identmin(long *array, int size);
// long	identmax(long *array, int size);
// long	*sortie(long *array, int size);
// void	preset(long *sorted, t_stack **stack, int size);
// int		errorinput(int size);
// void	freestack(t_stack **stack);

// char	*get_next_line(int fd);
// void	ft_alloc(t_fdf *nbr);
// void	check_arg(char **av);
// void	ft_error(char *str, int fd);
// long	ft_atoh(char *str);
// int		ft_count_nbr(char *nbr);
// void	ft_put_pixel(t_fdf *pic, int x, int y, long color);
// void	ft_error_sq(char *str, int fd, t_fdf *nbr);
// void	file_reader(t_fdf *nbr, char *str);
// void	ft_check_fd(char *str, int fd, t_fdf *nbr);
// void	ft_close(t_fdf *cs);

#endif
