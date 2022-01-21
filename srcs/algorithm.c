/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:17:46 by dimioui           #+#    #+#             */
/*   Updated: 2022/01/21 17:05:05 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	coloring(int val)
{
	int		nval;

	nval = (200 * val) / MAX_ITER;
	if (val == MAX_ITER)
		return (0);
	/*else if (val <=50)
		return (0xa2f70);
	else if (val <=100)
		return (0xd4c00b);
	else if (val <=150)
		return (0xeba400);
	else if (val <=200)
		return (0xd4670b);
	else if (val <=250)
		return (0xf70cf4);
	else if (val <=300)
		return (0x670bd4);
	else if (val <=350)
		return (0x0114eb);
	else if (val <=400)
		return (0x0b86d4);
	else if (val <=450)
		return (0x00f5d0);*/
	return (create_trgb(nval));
}

static int	cardioid_check(float x, float y)
{
	float	q;

	q = (x * x) + (y * y) - .5*x + .0625;
	if (((q * q) + (q * x) - .25 * q) <= .25 * y * y)
		return (1);
	return (0);
}

int	mandelbrot(t_complex z, t_complex c)
{
	long double	square_x;
	long double	square_y;
	int			iter;

	c.x = (2 * c.x) / RES_X - 1.5;
	c.y = (2 * c.y) / RES_Y - 1;
	square_x = z.x * z.x;
	square_y = z.y * z.y;
	iter = 0;
	if (cardioid_check(c.x, c.y))
		return (0);
	while ((square_x + square_y)<= 4 && iter < MAX_ITER)
	{
		z.y = c.y + (z.x + z.x) * z.y;
		z.x = c.x + square_x - square_y;
		square_x = z.x * z.x;
		square_y = z.y * z.y;
		iter++;
	}
	return (coloring(iter));
}

int	julia(t_complex z, t_complex c)
{
	long double	square_x;
	long double	square_y;
	int			iter;

	z.x = (4 * z.x) / RES_X;
	z.y = (4 * z.y) / RES_Y;
	square_x = z.x * z.x;
	square_y = z.y * z.y;
	iter = 0;
	while ((square_x + square_x) <= 4 && iter < MAX_ITER)
	{
		z.y = c.y + (z.x + z.x) * z.y;
		z.x = c.x + square_x - square_y;
		square_x = z.x * z.x;
		square_y = z.y * z.y;
		iter++;
	}
	return (coloring(iter));
}
