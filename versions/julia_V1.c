/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 13:00:07 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/04/19 18:39:12 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_zoom(int click, int x, int y, t_image *image)
{
	int		k;
	int		j;
//	(void)x;
//	(void)y;	
	k = 1;
	j = 1;
	printf(RED"click = %d\tx = %d\ty = %d\n"RESET, click, x, y);
	if (click == 4 && image->ca.zoom - 0.5 > 0) //out
	{
		if (x < image->img_w / 2)
			k = -1;
		if (y < image->img_h / 2)
			j = -1;
		image->ca.x = ( x / image->img_w * image->ca.cre) - (k * image->ca.cre);
		image->ca.y = ( y / image->img_h * image->ca.cim) - (j * image->ca.cim);
	//	image->ca.x = k * ( x / image->img_w * 1.5);
	//	image->ca.y = j * ( y / image->img_h * 1.2);
//		image->ca.x =( x - image->img_w / 2) / image->img_w ;
//		image->ca.y = -1 * ( y - image->img_h / 2) / image->img_h;
		image->ca.zoom = image->ca.zoom - 0.5;
		printf(BLUE"ca.x = %f\tca.y = %f\tk = %d\t j = %d\n"RESET, image->ca.x, image->ca.y, k, j);
		printf(BLUE"ca.zoom in = %f\n"RESET, image->ca.zoom);
		ft_julia(image->f ,image->pc, image->ca);
	}
	if (click == 5 && image->ca.zoom + 0.5 > 0) //in
	{
		if (x < image->img_w / 2)
			k = -1;
		if (y < image->img_h / 2)
			j = -1;
	//	image->ca.x =0 - ( x / image->img_w * image->ca.cre);
	//	image->ca.y =0 - ( y / image->img_h * image->ca.cim);
		image->ca.x = ( x / image->img_w * image->ca.cre) - (k * image->ca.cre);
		image->ca.y = ( y / image->img_h * image->ca.cim) - (j * image->ca.cim);
	//	image->ca.x = k * ( x / image->img_w * 1.5);
	//	image->ca.y = j * ( y / image->img_h * 1.2);
	//	image->ca.x =( x - image->img_w / 2) / image->img_w ;
	//	image->ca.y = -1 * ( y - image->img_h / 2) / image->img_h;
		image->ca.zoom = image->ca.zoom + 0.5;
		printf(YELLOW"ca.x = %f\tca.y = %f\tk = %d\t j = %d\n"RESET, image->ca.x, image->ca.y, k, j);
		printf(YELLOW"ca.zoom out = %f\n"RESET, image->ca.zoom);
		ft_julia(image->f ,image->pc, image->ca);
	}
	return (0);
}

int		ft_hook(int x, int y, t_image *image)
{
	//t_calc ca;

	if (x < 0 || x >= image->img_w || y < 0 || y >= image->img_h)
		return (0);
	printf("x = %d, y = %d\n", x, y);
	image->ca.cre = x / image->img_w * 100;
	image->ca.cim = y / image->img_h * 100;
/*			ca.cre = 1.5 * (x - image->img_w / 2) / (0.5 * image->img_w) + x;
			ca.cim = (y - image->img_h / 2) / (0.5 * image->img_h) + y;
			while (ca.cre >= 4 || ca.cim >= 4)
			{
				ca.cre = ca.cre / 4;
				ca.cim = ca.cim / 4;
			}
				ca.cre = ca.cre - 4;
				ca.cim = ca.cim - 4;*/
	ft_julia(image->f ,image->pc, image->ca);
	return(0);
}

int		ft_julia_key(int keycode, t_image *image)
{
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
	if (keycode == 82)
	{
		mlx_destroy_image(image->f.mlx, image->image);
		image->ca.zoom = 1;
		image->ca.x = 0;
		image->ca.y = 0;
		ft_julia(image->f ,image->pc, image->ca);
	}
	return (0);
}

void	get_point_julia(t_image *image, t_point point, t_calc ca)
{
//	double	cre;
//	double	cim;
	double	pre;
	double	pim;
	double	tmp;
//	double	zoom_x = 1;
//	double	zoom_y = 1;
//	double	x = 0;
//	double	y = 0;
//	double	x = ca.cre; //deplace la fractale selon x; avec ca.cre = x / image->img_w * 100;
//	double	y = ca.cim; //deplace la fractale selon y; avec ca.cim = y / image->img_h * 100;
	int		i;

/*	cre = -0.7;
	cim = 0.27015;*/
	
	printf("ca.cre = %f, ca.cim = %f\n", ca.cre, ca.cim);
//	point.y = 0;
	while (point.y < image->img_h)
	{
		point.x = 0;
		while (point.x < image->img_w)
		{
			pre = 1.5 * (point.x - image->img_w / 2) / (0.5 * ca.zoom * image->img_w) + ca.x;
			pim = (point.y - image->img_h / 2) / (0.5 * ca.zoom * image->img_h) + ca.y;
			i = 0;
			tmp = 0;
			while ((pre * pre + pim * pim) < 4 && i < ITER_MAX_JU)
			{
				tmp = pre;
				pre = pre * pre - pim * pim + ca.cre;
				pim = 2 * tmp * pim + ca.cim;
				i++;
			}
			point.x++;
			if ((pre * pre + pim * pim) >= 4)
				get_colour(i, image, point, ITER_MAX_JU);
		}
		point.y++;
	}
}
