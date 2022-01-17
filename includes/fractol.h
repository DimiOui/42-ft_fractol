/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:01:58 by dimioui           #+#    #+#             */
/*   Updated: 2022/01/17 16:44:03 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define MAX_ITER 50
# define RES_X 800
# define RES_Y 800
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define ESC 65307
# define SCROLLUP 4
# define SCROLLDOWN 5

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		offset_x;
	int		offset_y;
	void	*mlx;
	void	*mlx_win;
	float	zoom;
	float	cx;
	float	cy;
}	t_data;

typedef struct s_complex {
	float	x;
	float	y;
}	t_complex;

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <math.h>
# include <stdlib.h>

int		mandelbrot(t_complex s, t_complex c, t_data *data);
int		kh_mouse(int x, int y);
int		kh_keeb(int keycode, t_data *data);
int		create_trgb(int hue);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
