/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 13:00:07 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/05/14 00:05:02 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_zoom_ju(int click, int x, int y, t_image *image)
{
	if (click == 5)
	{
		zoom_init(image, x, y, 0.4);
		ft_destroy_create_julia(image);
	}
	if (click == 4)
	{
		zoom_init(image, x, y, 0.6);
		ft_destroy_create_julia(image);
	}
	return (0);
}

int		ft_hook(int x, int y, t_image *image)
{
	if (image->status_mouse == 1)
	{
		if (x < 0 || x >= image->img_w || y < 0 || y >= image->img_h)
			return (0);
		image->ca.cre = (x * (image->ca.x2 - image->ca.x1) / image->img_w) \
						+ image->ca.x1;
		image->ca.cim = (y * (image->ca.y2 - image->ca.y1) / image->img_h) \
						+ image->ca.y1;
		ft_destroy_create_julia(image);
	}
	return (0);
}

int		ft_julia_key(int keycode, t_image *image)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 36)
		image->status_mouse = (image->status_mouse == 0) ? 1 : 0;
	else if (keycode == 82)
	{
		image->ca.cre = -0.7;
		image->ca.cim = 0.27015;
		image->ca.x1 = -1.7;
		image->ca.y1 = -1.2;
		image->ca.x2 = 1.7;
		image->ca.y2 = 1.2;
		ft_destroy_create_julia(image);
	}
	else if (keycode >= 123 && keycode <= 126)
	{
		ft_directionkey(keycode, image);
		ft_destroy_create_julia(image);
	}
	return (0);
}

int		ft_draw_ju(t_point point, t_calc ca)
{
	double		z_r;
	double		z_i;
	double		tmp;
	int			i;

	z_r = point.x / ca.zoom_x + ca.x1;
	z_i = point.y / ca.zoom_y + ca.y1;
	i = 0;
	while (z_r * z_r + z_i * z_i < 4 && i < ITER_MAX_JU)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + ca.cre;
		z_i = 2 * z_i * tmp + ca.cim;
		i++;
	}
	return (i);
}

void	get_point_julia(t_image *image, t_point point, t_calc ca)
{
	int		i;

	ca.zoom_x = image->img_w / (ca.x2 - ca.x1);
	ca.zoom_y = image->img_h / (ca.y2 - ca.y1);
	point.x = 0;
	while (point.x < image->img_w)
	{
		point.y = 0;
		while (point.y < image->img_h)
		{
			i = ft_draw_ju(point, ca);
			if (i != ITER_MAX_JU)
				get_colour(i, image, point, ITER_MAX_JU);
			point.y++;
		}
		point.x++;
	}
}
