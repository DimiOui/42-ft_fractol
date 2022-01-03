/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaccagn <dpaccagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:36:32 by dpaccagn          #+#    #+#             */
/*   Updated: 2022/01/03 15:26:34 by dpaccagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>

int	create_trgb(int t, int r, int g, int b);

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	float		i;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 800, "Hello world!");
	img.img = mlx_new_image(mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	i = 0;
	while (i < 2*M_PI)
	{
		my_mlx_pixel_put(&img, cos(i)*200+400, sin(i)*200+400, create_trgb(0, 0, 255, 0));
		i+=0.001;
	}
	i = 0;
	while (i < M_PI)
	{
		my_mlx_pixel_put(&img, cos(i)*150+400, sin(i)*150+400, create_trgb(0, 0, 255, 0));
		i+=0.001;
	}
	i = 0;
	while (i < 2*M_PI)
	{
		my_mlx_pixel_put(&img, cos(i)*15+300, sin(i)*15+250, create_trgb(0, 255, 0, 0));
		i+=0.001;
	}
	i = 0;
		while (i < 2*M_PI)
	{
		my_mlx_pixel_put(&img, cos(i)*15+500, sin(i)*15+250, create_trgb(0, 255, 0, 0));
		i+=0.001;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
