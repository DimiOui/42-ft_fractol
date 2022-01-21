/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:34:51 by dimioui           #+#    #+#             */
/*   Updated: 2022/01/21 16:02:49 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, RES_X, RES_Y, "Hello world!");
	data->img = mlx_new_image(data->mlx, RES_X, RES_Y);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
					&data->line_length, &data->endian);
	data->zoom = 1;
	data->xpos = 0;
	data->ypos = 0;
}

int	main(void)
{
	t_data	data;

	ft_init_mlx(&data);
	mlx_hook(data.mlx_win, 4, 1L<<2, kh_mousezoom, &data);
	mlx_hook(data.mlx_win, 2, 1L<<0, kh_keeb, &data);
	ft_fill_screen(&data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_loop(data.mlx);
	return (0);
}

//1L << 4
