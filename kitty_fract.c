/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kitty_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:52:59 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/04/15 22:22:47 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_kitty_key(int keycode, t_image *image)
{
	(void)image;
	if (keycode == 53)
		exit(0);
	return (0);
}

void	draw_circle(t_image *image, double x_orig, double y_orig, int r)
{
	double		x;
	double		y;

	y = -r;
	while (y < (r + 1))
	{
		x = -r;
		while (x < (r + 1))
		{
				if (fabs((x * x) + (y * y) - (r * r)) <= (r / 2))
					ft_pixel_put_img(image, x_orig + x, y_orig + y, 0x0099FF);
			x = x + 0.5;
		}
		y = y + 0.5;
	}
}

void	recursion(t_circle circle, double x_orig, double y_orig, int r)
{
	if (circle.r > 1)
	{
//		circle.x_orig = circle.x_orig + (circle.r * 0.67);
		draw_circle(circle.image, x_orig, y_orig, r);
		circle.r = circle.r * 0.67;
		circle.i++;
		recursion(circle, x_orig + circle.r + r, y_orig, r * 0.67);
		recursion(circle, x_orig - circle.r - r, y_orig, r * 0.67); 
//		recursion(circle, x_orig, y_orig + circle.r + r, r * 0.67); 
	}
}

void	get_point_kitty(t_image *image, t_point point)
{
	t_circle 	circle;

	point.colour = 0x0099FF;
	circle.x_orig = image->img_w / 2;
	circle.y_orig = image->img_h / 2;
	circle.r = 150;
	circle.i = 0;
	circle.image = image;
//	circle.colour = 0x0099FF;
	recursion(circle, circle.x_orig, circle.y_orig, circle.r);
}
