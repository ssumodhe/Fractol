/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_fract.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:32:50 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/05/09 16:52:57 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mandelbrot_key(int keycode, t_image *image)
{
	(void)image;
	if (keycode == 53)
		exit(0);
	return (0);
}

void	get_point_mandelbrot(t_image *image, t_point point)
{
	double	x = -0.75;
	double	y = 0;
	double	zre;
	double	zim;
	double	pre;
	double	pim;
	double	tmp;
	double	zoom_x = 0.8;
	double	zoom_y = 0.8;
	int		i;
	
	point.y = 0;
	while (point.y < image->img_h)
	{
		pim = (point.y - image->img_h / 2) / (0.5 * zoom_y * image->img_h) + y;
		point.x = 0;
		while (point.x < image->img_w)
		{
			pre = 1.5 * (point.x - image->img_w / 2) / (0.5 * zoom_x * image->img_w) + x;
			i = 0;
			zim = 0;
			zre = 0;
			tmp = 0;
			while ((zre * zre + zim * zim) < 4 && i < ITER_MAX_MAN)
			{
				tmp = zre;
				zre = zre * zre - zim * zim + pre;
				zim = 2 * tmp * zim + pim;
				i++;
			}
			point.x++;
			if ((zre * zre + zim * zim) >= 4)
				get_colour(i, image, point, ITER_MAX_MAN);
		}
		point.y++;
	}
}
