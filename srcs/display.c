/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:34:18 by dimioui           #+#    #+#             */
/*   Updated: 2022/01/27 12:27:16 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x
			* (data ->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_fill_screen(t_data *data, int (*f)(t_complex, t_complex))
{
	long double		i;
	long double		j;
	t_complex		c;
	t_complex		z;
	int				t;

	i = 0;
	while (i++ < RES_X)
	{
		j = 0;
		while (j++ < RES_Y)
		{
			t = (!ft_strncmp(data->fractal, "mandelbrot", 11));
			c.x = t * (data->xpos + (i * data->zoom)) + (1 - t) * (data->cx);
			c.y = t * (data->ypos + (j * data->zoom)) + (1 - t) * (data->cy);
			z.x = (1 - t) * (data->xpos + (i * data->zoom));
			z.y = (1 - t) * (data->ypos + (j * data->zoom));
			my_mlx_pixel_put(data, i, j, f(z, c));
		}
	}
}

/*void	ft_fill_screen(t_data *data, int (*f)(t_complex, t_complex))
{
	float		i;
	float		j;
	t_complex	c;
	t_complex	z;

	i = 0;
	while (i++ < RES_X)
	{
		j = 0;
		while (j++ < RES_Y)
		{
			if (!ft_strncmp(data->fractal, "mandelbrot", 11))
			{
				c.x = data->xpos + (i * data->zoom);
				c.y = data->ypos + (j * data->zoom);
				z.x = 0;
				z.y = 0;
			}
			else
			{
				c.x = data->cx;
				c.y = data->cy;
				z.x = data->xpos + (i * data->zoom);
				z.y = data->ypos + (j * data->zoom);
			}
			my_mlx_pixel_put(data, i, j, f(z, c));
		}
	}
}*/
