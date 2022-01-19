/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaccagn <dpaccagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:17:46 by dimioui           #+#    #+#             */
/*   Updated: 2022/01/19 13:05:21 by dpaccagn         ###   ########.fr       */
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

int	mandelbrot(t_complex z, t_complex c)
{
	float	square_x;
	float	square_y;
	int		iter;

	c.x = (2.25 * c.x )/ 800 - 2;
	c.y = (2 * c.y) / 800 - 1;
	square_x = z.x * z.x;
	square_y = z.y * z.y;
	iter = 0;
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
