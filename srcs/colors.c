/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaccagn <dpaccagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:05:18 by dpaccagn          #+#    #+#             */
/*   Updated: 2022/01/19 13:06:03 by dpaccagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_getr(int hue)
{
	int	r;

	if (hue <= 16 || hue > 84)
		r = 255;
	else if (hue <= 33)
		r = 255 - ((255 * (hue - 16)) / 16);
	else if (hue <= 66)
		r = 0;
	else
		r = 255 * (hue - 66) / 16;
	return (r);
}

static int	ft_getg(int hue)
{
	int	g;

	if (hue <= 16)
		g = (255 * hue) / 16;
	else if (hue <= 50)
		g = 255;
	else if (hue <= 66)
		g = 255 - (255 * (hue - 50) / 16);
	else
		g = 0;
	return (g);
}

static int	ft_getb(int hue)
{
	int	b;

	if (hue <= 33)
		b = 0;
	else if (hue <= 50)
		b = (255 * (hue - 33) / 16);
	else if (hue <= 84)
		b = 255;
	else
		b = 255 - (255 * (hue - 84) / 16);
	return (b);
}

int	create_trgb(int hue)
{
	int	r;
	int	g;
	int	b;

	r = ft_getr(hue);
	g = ft_getg(hue);
	b = ft_getb(hue);
	return (0 << 24 | r << 16 | g << 8 | b);
}
