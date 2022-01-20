/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaccagn <dpaccagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:18:41 by dimioui           #+#    #+#             */
/*   Updated: 2022/01/20 13:55:35 by dpaccagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*int	kh_mouse(int x, int y)
{
	printf("xpos: %d, ypos: %d\n", x, y);
	return (0);
}*/

int	kh_mousezoom(int keycode, int x, int y, t_data *data)
{
	(void)		x;
	(void)		y;
	//float		centered_x;
	//float		centered_y;

	//centered_y = (y / (y * 0.00125)) * 0.5;
	//centered_x = (x / (x * 0.00125)) * 0.5;
	if (keycode == L_CLICK)
		data->zoom /= 1.25;
	else if (keycode == R_CLICK)
		data->zoom *= 1.25;
	data->xpos = x;
	data->ypos = y;
	ft_fill_screen(data);
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
	//else if (keycode == LEFT)
	//	data->offset_x -= 25 / data->zoom;
	//else if (keycode == UP)
	//	data->offset_y -= 25 / data->zoom;
	//else if (keycode == RIGHT)
	//	data->offset_x += 25 / data->zoom;
	//else if (keycode == DOWN)
	//	data->offset_y += 25 / data->zoom;
	return (0);
}
