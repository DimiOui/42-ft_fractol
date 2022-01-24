/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaccagn <dpaccagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:34:18 by dimioui           #+#    #+#             */
/*   Updated: 2022/01/24 12:50:20 by dpaccagn         ###   ########.fr       */
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
}
