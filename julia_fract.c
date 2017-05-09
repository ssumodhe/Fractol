/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 13:00:07 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/05/09 18:39:15 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int		ft_zoom(int click, int x, int y, t_image *image) //void??
{
	double	x_tmp;
	double	y_tmp;
	double	tmp;
	double	d_x;
	double	d_y;
	printf(RED"click = %d\tx = %d\ty = %d\n"RESET, click, x, y);
	if (click == 5) //out
	{
		x_tmp = (x * (image->ca.x2 - image->ca.x1) / image->img_w) + image->ca.x1;
		y_tmp = (y * (image->ca.y2 - image->ca.y1) / image->img_h) + image->ca.y1;

		d_x = image->ca.x2 - image->ca.x1;
		d_y = image->ca.y2 - image->ca.y1;
		tmp = image->ca.x1;

		image->ca.x1 = (x_tmp + (image->ca.x2 + image->ca.x1) / 2) / 2 - d_x * 0.4;
		image->ca.x2 = (x_tmp + (image->ca.x2 + tmp) / 2) / 2 + d_x * 0.4;

		tmp = image->ca.y1;

		image->ca.y1 = (y_tmp + (image->ca.y2 + image->ca.y1) / 2) / 2 - d_y * 0.4;
		image->ca.y2 = (y_tmp + (image->ca.y2 + tmp) / 2) / 2 + d_y * 0.4;

		ft_julia(image->f ,image->pc, image->ca);
	}
	
	if (click == 4) //in
	{
		x_tmp = (x * (image->ca.x2 - image->ca.x1) / image->img_w) + image->ca.x1;
		y_tmp = (y * (image->ca.y2 - image->ca.y1) / image->img_h) + image->ca.y1;

		d_x = image->ca.x2 - image->ca.x1;
		d_y = image->ca.y2 - image->ca.y1;
		tmp = image->ca.x1;

		image->ca.x1 = (x_tmp + (image->ca.x2 + image->ca.x1) / 2) / 2 - d_x * 0.6;
		image->ca.x2 = (x_tmp + (image->ca.x2 + tmp) / 2) / 2 + d_x * 0.6;

		tmp = image->ca.y1;

		image->ca.y1 = (y_tmp + (image->ca.y2 + image->ca.y1) / 2) / 2 - d_y * 0.6;
		image->ca.y2 = (y_tmp + (image->ca.y2 + tmp) / 2) / 2 + d_y * 0.6;

		ft_julia(image->f ,image->pc, image->ca);
	}
	return (0);
}

int		ft_hook(int x, int y, t_image *image)
{
	//t_calc ca;

	if (x < 0 || x >= image->img_w || y < 0 || y >= image->img_h)
		return (0);
//	image->ca.cre = image->ca.cre - 0.01;
//	image->ca.cim = image->ca.cim - 0.01;

		image->ca.cre = (x * (image->ca.x2 - image->ca.x1) / image->img_w) + image->ca.x1;
		image->ca.cim = (y * (image->ca.y2 - image->ca.y1) / image->img_h) + image->ca.y1;
		printf("cre = %f, cim = %f\n", image->ca.cre, image->ca.cim);
	ft_julia(image->f ,image->pc, image->ca);
	return(0);
}

int		ft_julia_key(int keycode, t_image *image)
{
	(void)image;
	printf("keycode = %d\n", keycode);
	if (keycode == 53) // touche esc
		exit(0);
	if(keycode == 36) // touche enter
	{
		mlx_destroy_image(image->f.mlx, image->image);
		mlx_hook(image->f.win_1, 6, 0, ft_hook, image);
	}
	if (keycode == 258 || keycode == 257) // touche shift-droite et touche shift-gauche
	{
		mlx_destroy_image(image->f.mlx, image->image);
		mlx_hook(image->f.win_1, 4, 0, ft_zoom, image);
	}
	if (keycode == 82) // touche 0
	{
		mlx_destroy_image(image->f.mlx, image->image);
		image->ca.cre = -0.7;
		image->ca.cim = 0.27015;
		image->ca.x1 = -1.7;
		image->ca.y1 = -1.2;
		image->ca.x2 = 1.7;
		image->ca.y2 = 1.2;
		ft_julia(image->f ,image->pc, image->ca);
	}
	if (keycode == 123) // fleche gauche
	{
		mlx_destroy_image(image->f.mlx, image->image);
		image->ca.x1 = image->ca.x1 + 0.01;
		image->ca.x2 = image->ca.x2 + 0.01;
		ft_julia(image->f ,image->pc, image->ca);
	}
	if (keycode == 124) // fleche droite
	{
		mlx_destroy_image(image->f.mlx, image->image);
		image->ca.x1 = image->ca.x1 - 0.01;
		image->ca.x2 = image->ca.x2 - 0.01;
		ft_julia(image->f ,image->pc, image->ca);
	}
	if (keycode == 126) // fleche haut
	{
		mlx_destroy_image(image->f.mlx, image->image);
		image->ca.y1 = image->ca.y1 + 0.01;
		image->ca.y2 = image->ca.y2 + 0.01;
		ft_julia(image->f ,image->pc, image->ca);
	}
	if (keycode == 125) // fleche bas
	{
		mlx_destroy_image(image->f.mlx, image->image);
		image->ca.y1 = image->ca.y1 - 0.01;
		image->ca.y2 = image->ca.y2 - 0.01;
		ft_julia(image->f ,image->pc, image->ca);
	}

	return (0);
}

void	get_point_julia(t_image *image, t_point point, t_calc ca)
{
	//	int		x;
	//	int		y;
	//	double	x1 = -1.7;
	//	double	x2 = 1.7;
	//	double	y1 = -1.2;
	//	double	y2 = 1.2;
	double	zoom_x;
	double	zoom_y;
	//	double	c_r;
	//	double 	c_i;
	double 	z_r;
	double 	z_i;
	double 	tmp;
	int		i;

//	(void)ca;

	zoom_x = image->img_w / (ca.x2 - ca.x1);
	zoom_y = image->img_h / (ca.y2 - ca.y1);

	point.x = 0;
	while (point.x < image->img_w)
	{
		point.y = 0;
		while (point.y < image->img_h)
		{
			z_r = point.x / zoom_x + ca.x1;
			z_i = point.y / zoom_y + ca.y1;
			i = 0;
			while (z_r *z_r + z_i *z_i < 4 && i <  ITER_MAX_JU)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + ca.cre;
				z_i = 2 * z_i * tmp + ca.cim;
				i++;
			}

			if (/*z_r *z_r + z_i *z_i >= 4*/i != ITER_MAX_JU)
				get_colour(i, image, point, ITER_MAX_MAN);
			point.y++;
		}
		point.x++;
	}
}
