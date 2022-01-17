/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:18:41 by dimioui           #+#    #+#             */
/*   Updated: 2022/01/17 16:41:52 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	kh_mouse(int x, int y)
{
	printf("xpos: %d, ypos: %d\n", x, y);
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
		data->offset_x -= 25 / data->zoom;
	else if (keycode == UP)
		data->offset_y -= 25 / data->zoom;
	else if (keycode == RIGHT)
		data->offset_x += 25 / data->zoom;
	else if (keycode == DOWN)
		data->offset_y += 25 / data->zoom;
	return (0);
}
