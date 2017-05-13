/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 22:43:12 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/05/13 23:56:43 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_directionkey(int keycode, t_image *image)
{
	if (keycode == 123)
	{
		image->ca.x1 = image->ca.x1 + 0.01;
		image->ca.x2 = image->ca.x2 + 0.01;
	}
	else if (keycode == 124)
	{
		image->ca.x1 = image->ca.x1 - 0.01;
		image->ca.x2 = image->ca.x2 - 0.01;
	}
	else if (keycode == 126)
	{
		image->ca.y1 = image->ca.y1 + 0.01;
		image->ca.y2 = image->ca.y2 + 0.01;
	}
	else if (keycode == 125)
	{
		image->ca.y1 = image->ca.y1 - 0.01;
		image->ca.y2 = image->ca.y2 - 0.01;
	}
}

void	zoom_init(t_image *image, int x, int y, double zoom)
{
	double	x_tmp;
	double	y_tmp;
	double	tmp;
	double	d_x;
	double	d_y;

	x_tmp = (x * (image->ca.x2 - image->ca.x1) / image->img_w) + image->ca.x1;
	y_tmp = (y * (image->ca.y2 - image->ca.y1) / image->img_h) + image->ca.y1;
	d_x = image->ca.x2 - image->ca.x1;
	d_y = image->ca.y2 - image->ca.y1;
	tmp = image->ca.x1;
	image->ca.x1 = (x_tmp + (image->ca.x2 + image->ca.x1) / 2) / 2 - d_x * zoom;
	image->ca.x2 = (x_tmp + (image->ca.x2 + tmp) / 2) / 2 + d_x * zoom;
	tmp = image->ca.y1;
	image->ca.y1 = (y_tmp + (image->ca.y2 + image->ca.y1) / 2) / 2 - d_y * zoom;
	image->ca.y2 = (y_tmp + (image->ca.y2 + tmp) / 2) / 2 + d_y * zoom;
}

void	pick_fract(int check)
{
	t_fractol	f;
	t_point		pc;

	f.mlx = mlx_init();
	pc.y = 0;
	if (check == 1 || check == 2 || check == 3 || check == 5 || check == 6 || \
		check == 9 || check == 14 || check == 15 || check == 18 || check == 27 \
		|| check == 41 || check == 45 || check == 54 || check == 81)
		init_julia(f, pc);
	if (check == 4 || check == 8 || check == 9 || check == 12 || check == 5 || \
		check == 17 || check == 18 || check == 44 || check == 45 || \
		check == 57 || check == 84 || check == 21 || check == 30 || \
		check == 6)
		init_mandelbrot(f, pc);
	if (check == 13 || check == 26 || check == 39 || check == 14 || \
		check == 15 || check == 17 || check == 18 || check == 27 || \
		check == 53 || check == 54 || check == 57 || check == 93 || \
		check == 21 || check == 30)
		init_douady(f, pc);
	mlx_loop(f.mlx);
}
