/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:17:46 by dimioui           #+#    #+#             */
/*   Updated: 2022/01/20 16:21:21 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	coloring(int val)
{
	int		nval;

	nval = (100 * val) / MAX_ITER;
	if (val == MAX_ITER)
		return (0);
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
	float	square_x;
	float	square_y;
	int		iter;

	c.x = (2.25 * c.x) / RES_X - 1.75;
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
