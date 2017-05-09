/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_2_fract.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:27:00 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/05/09 16:34:43 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_colours	colours_2(double h,double c, double x)
{
	t_colours	col;

	if (h >= 180 && h < 240)
	{
		col.red = 0;
		col.green = x;
		col.blue = c;
	}
	if (h >= 240 && h < 300)
	{
		col.red = x;
		col.green = 0;
		col.blue = c;
	}
	if (h >= 300 && h < 360)
	{
		col.red = c;
		col.green = 0;
		col.blue = x;
	}
	return (col);
}

t_colours	colours_1(double h, double c, double x)
{
	t_colours	col;

	if (h >= 0 && h < 60)
	{
		col.red = c;
		col.green = x;
		col.blue = 0;
	}
	if (h >= 60 && h < 120)
	{
		col.red = x;
		col.green = c;
		col.blue = 0;
	}
	if (h >= 120 && h < 180)
	{
		col.red = 0;
		col.green = c;
		col.blue = x;
	}
	return (col);
}

void		get_colour(int colour, t_image *img, t_point point, double iter_max)
{
	t_cal_col	c_col;
	t_colours	col;

	c_col.h = (colour * 360) / iter_max;
	c_col.l = 0.5;
	c_col.s = 1;
	c_col.c = (1 - fabs((2*c_col.l) - 1)) * c_col.s;
	c_col.radian = 60 * M_PI / 180;
	c_col.x = c_col.c * (1 - fabs(((c_col.h / cos(c_col.radian)) / 2) - 1));
	c_col.m = c_col.l - (c_col.c / 2);
	if (c_col.h >= 0 && c_col.h < 180)
		col = colours_1(c_col.h, c_col.c, c_col.x);
	else if (c_col.h >= 180 && c_col.h < 360)
		col = colours_2(c_col.h, c_col.c, c_col.x);
	if (point.x >= 0 && point.y >= 0 && point.x < img->img_w)
	{
		c_col.i = (4 * (point.x + (point.y * img->img_w)));
		if (c_col.i < (4 * img->img_w * img->img_h) - 4)
		{
			img->img_addr[c_col.i + 0] = (col.blue + c_col.m) * 255;
			img->img_addr[c_col.i + 1] = (col.green + c_col.m) * 255;
			img->img_addr[c_col.i + 2] = (col.red + c_col.m) * 255;
			img->img_addr[c_col.i + 3] = 0x00;
		}
	}
}

void	put_frame(t_image *image, t_point point)
{
	point.colour = 0x00FFFFFF;
	point.x1 = 0;
	point.y1 = 0;
	point.x2 = image->img_w - 1;
	point.y2 = 0;
	ft_drawline_img(image, point);
	point.x1 = image->img_w - 1;
	point.y1 = 0;
	point.x2 = image->img_w - 1;
	point.y2 = image->img_h - 1;
	ft_drawline_img(image, point);
	point.x1 = image->img_w - 1;
	point.y1 = image->img_h - 1;
	point.x2 = 0;
	point.y2 = image->img_h - 1;
	ft_drawline_img(image, point);
	point.x1 = 0;
	point.y1 = image->img_h - 1;
	point.x2 = 0;
	point.y2 = 0;
	ft_drawline_img(image, point);
}
