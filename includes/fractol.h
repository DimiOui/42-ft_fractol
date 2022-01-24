/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaccagn <dpaccagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:01:58 by dimioui           #+#    #+#             */
/*   Updated: 2022/01/24 10:06:30 by dpaccagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define MAX_ITER 500
# define RES_X 800
# define RES_Y 800
# define ESC 65307
# define L_CLICK 1
# define R_CLICK 3

typedef struct s_data {
	char	*fractal;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
	float	zoom;
	float	ypos;
	float	xpos;
}	t_data;

typedef struct s_complex {
	long double	x;
	long double	y;
}	t_complex;

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <math.h>
# include <stdlib.h>
# include "libft.h"

int		mandelbrot(t_complex s, t_complex c);
int		kh_mousezoom(int keycode, int x, int y, t_data *data);
int		kh_keeb(int keycode, t_data *data);
int		create_trgb(int hue);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_fill_screen(t_data *data, int (*f)(t_complex, t_complex));
void	draw_fractal(t_data *data);
int		julia(t_complex z, t_complex c);

#endif
