/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaccagn <dpaccagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:34:51 by dimioui           #+#    #+#             */
/*   Updated: 2022/01/19 14:06:37 by dpaccagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_data	*data;

	data = malloc (sizeof(t_data));
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, RES_X, RES_Y, "Hello world!");
	data->img = mlx_new_image(data->mlx, RES_X, RES_Y);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,
								&data->endian);
	ft_fill_screen(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	mlx_hook(data->mlx_win, 6, 1L<<6, kh_mouse, &data);
	mlx_hook(data->mlx_win, 2, 1L<<0, kh_keeb, &data);
	mlx_loop(data->mlx);
}
