/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaccagn <dpaccagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:18:41 by dimioui           #+#    #+#             */
/*   Updated: 2022/01/24 14:02:26 by dpaccagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	kh_mousezoom(int keycode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (keycode == ZOOM_IN)
	{
		data->zoom /= 1.25;
		data->xpos += data->zoom * (x - (RES_X / 2));
		data->ypos += data->zoom * (y - (RES_Y / 2));
	}
	else if (keycode == ZOOM_OUT)
	{
		data->zoom *= 1.25;
		data->xpos += data->zoom * (x - (RES_X / 2));
		data->ypos += data->zoom * (y - (RES_Y / 2));
	}
	else if (keycode == L_CLICK)
	{
		data->cx = 2 * ((float)x - RES_X / 2) / RES_X;
		data->cy = 2 * ((float)y - RES_Y / 2) / RES_Y;
	}
	draw_fractal(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}

int	kh_keeb(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
	}
	else if (keycode == LEFT)
		data->xpos -= 25 / data->zoom;
	else if (keycode == UP)
		data->ypos -= 25 / data->zoom;
	else if (keycode == RIGHT)
		data->xpos += 25 / data->zoom;
	else if (keycode == DOWN)
		data->ypos += 25 / data->zoom;
	draw_fractal(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}
