/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:05:18 by dpaccagn          #+#    #+#             */
/*   Updated: 2022/01/17 16:04:44 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	get_red(int hue)
{
	int	red;

	if (hue <= 16 || hue > 84)
		red = 255;
	else if (hue <= 33)
		red = 255 - ((255 * (hue - 16)) / 16);
	else if (hue <= 66)
		red = 0;
	else
		red = 255 * (hue - 66) / 16;
	return (red);
}

static int	get_green(int hue)
{
	int	green;

	if (hue <= 16)
		green = (255 * hue) / 16;
	else if (hue <= 50)
		green = 255;
	else if (hue <= 66)
		green = 255 - (255 * (hue - 50) / 16);
	else
		green = 0;
	return (green);
}

static int	get_blue(int hue)
{
	int	blue;

	if (hue <= 33)
		blue = 0;
	else if (hue <= 50)
		blue = (255 * (hue - 33) / 16);
	else if (hue <= 84)
		blue = 255;
	else
		blue = 255 - (255 * (hue - 84) / 16);
	return (blue);
}

int	create_trgb(int hue)
{
	int	r;
	int	g;
	int	b;

	r = get_red(hue);
	g = get_green(hue);
	b = get_blue(hue);
	return (0 << 24 | r << 16 | g << 8 | b);
}
