/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   douady_fract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 22:30:04 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/05/14 00:14:17 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_zoom_dou(int click, int x, int y, t_image *image)
{
	if (click == 5)
	{
		zoom_init(image, x, y, 0.4);
		ft_douady(image->f, image->pc, image->ca);
	}
	if (click == 4)
	{
		zoom_init(image, x, y, 0.6);
		ft_douady(image->f, image->pc, image->ca);
	}
	return (0);
}

int		ft_douady_key(int keycode, t_image *image)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 82)
	{
		mlx_destroy_image(image->f.mlx, image->image);
		image->ca.cre = 0.291757;
		image->ca.cim = 0.571200;
		image->ca.x1 = -1.7;
		image->ca.y1 = -1.2;
		image->ca.x2 = 1.7;
		image->ca.y2 = 1.2;
		ft_douady(image->f, image->pc, image->ca);
	}
	else if (keycode >= 123 && keycode <= 126)
	{
		mlx_destroy_image(image->f.mlx, image->image);
		ft_directionkey(keycode, image);
		ft_douady(image->f, image->pc, image->ca);
	}
	return (0);
}

int		ft_draw_dou(t_point point, t_calc ca)
{
	double		z_r;
	double		z_i;
	double		tmp;
	int			i;

	z_r = point.x / ca.zoom_x + ca.x1;
	z_i = point.y / ca.zoom_y + ca.y1;
	i = 0;
	while (z_r * z_r + z_i * z_i < 4 && i < ITER_MAX_DOU)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + ca.cre;
		z_i = 2 * z_i * tmp + ca.cim;
		i++;
	}
	return (i);
}

void	get_point_douady(t_image *image, t_point point, t_calc ca)
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
			i = ft_draw_dou(point, ca);
			if (i != ITER_MAX_DOU)
				get_colour(i, image, point, ITER_MAX_DOU);
			point.y++;
		}
		point.x++;
	}
}
