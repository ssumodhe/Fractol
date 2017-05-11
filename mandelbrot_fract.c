/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_fract.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:32:50 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/05/11 20:21:56 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_zoom_man(int click, int x, int y, t_image *image) //void??
{
	printf(GREEN"man - click = %d\tx = %d\ty = %d\n"RESET, click, x, y); //
	if (click == 5) //out
	{
		zoom_init(image, x, y, 0.4);
		ft_mandelbrot(image->f ,image->pc, image->ca);
	}
	
	if (click == 4) //in
	{
		zoom_init(image, x, y, 0.6);
		ft_mandelbrot(image->f ,image->pc, image->ca);
	}
	return (0);
}

int		ft_mandelbrot_key(int keycode, t_image *image)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 82) // touche 0
	{
		mlx_destroy_image(image->f.mlx, image->image);
		image->ca.x1 = -2.1;
		image->ca.y1 = -1.2;
		image->ca.x2 = 0.6;
		image->ca.y2 = 1.2;
		ft_mandelbrot(image->f ,image->pc, image->ca);
	}
	else if (keycode >= 123 && keycode <= 126)
	{
		mlx_destroy_image(image->f.mlx, image->image);
		ft_directionkey(keycode, image);
		ft_mandelbrot(image->f ,image->pc, image->ca);
	}
	return (0);
}

int		ft_draw_man(t_point point, t_calc ca)
{
	double 	z_r;
	double 	z_i;
	double 	tmp;
	int		i;

	z_r = 0;
	z_i = 0;
	ca.cre = point.x / ca.zoom_x + ca.x1;
	ca.cim = point.y / ca.zoom_y + ca.y1;
	i = 0;
	while (z_r *z_r + z_i *z_i < 4 && i <  ITER_MAX_MAN)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + ca.cre;
		z_i = 2 * z_i * tmp + ca.cim;
		i++;
	}
	return (i);
}

void	get_point_mandelbrot(t_image *image, t_point point, t_calc ca)
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
			i = ft_draw_man(point, ca);
			if (i != ITER_MAX_MAN)
				get_colour(i, image, point, ITER_MAX_MAN);
			point.y++;
		}
		point.x++;
	}
}
