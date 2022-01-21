/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:34:51 by dimioui           #+#    #+#             */
/*   Updated: 2022/01/21 16:50:39 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_data *data)
{
	if (!ft_strncmp(data->fractal, "mandelbrot", 11))
		ft_fill_screen(data, &mandelbrot);
	else if (!ft_strncmp(data->fractal, "julia", 6))
		ft_fill_screen(data, &julia);
}

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

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		ft_putstr_fd("Available parameters:\n", 2);
		ft_putstr_fd("\tmandelbrot\n", 2);
		ft_putstr_fd("\tjulia\n", 2);
		return (4);
	}
	data.fractal = av[1];
	ft_init_mlx(&data);
	mlx_hook(data.mlx_win, 4, 1L<<2, kh_mousezoom, &data);
	mlx_hook(data.mlx_win, 2, 1L<<0, kh_keeb, &data);
	draw_fractal(&data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_loop(data.mlx);
	return (0);
}
