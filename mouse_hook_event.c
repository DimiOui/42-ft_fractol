/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaccagn <dpaccagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:16:10 by dpaccagn          #+#    #+#             */
/*   Updated: 2022/01/07 12:48:12 by dpaccagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int x, int y, t_vars *vars)
{
	printf("xpos: %d, ypos: %d\n", x, y);
	//mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 800, "Hello world!");
	mlx_hook(vars.win, 6, 1L<<6, close, &vars);
	mlx_loop(vars.mlx);
}
