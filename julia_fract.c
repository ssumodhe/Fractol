/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 13:00:07 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/04/17 17:44:01 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_hook(int x, int y, t_image *image)
{
	t_calc ca;

	(void)image;
	printf("x = %d, y = %d\n", x, y);
	ca.cre = -0.6;
	ca.cim = 0.27016;
	get_point_julia(image,image->pc, ca);
	return(0);
}

int		ft_julia_key(int keycode, t_image *image)
{
	if (keycode == 53)
		exit(0);
	if(keycode == 36)
	{
		//mlx_clear_window(image->f.mlx, image->f.win_1);
		mlx_destroy_image(image->f.mlx, image->image);
		mlx_hook(image->f.win_1, 6, 0, ft_hook, image);
		put_frame(image, image->pc);
		mlx_put_image_to_window(image->f.mlx, image->f.win_1, image->image, 10, 10);
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
	double	zoom_x = 1;
	double	zoom_y = 1;
	double	x = 0;
	double	y = 0;
	int		i;

/*	cre = -0.7;
	cim = 0.27015;*/
	
	printf("x = %f, y = %f\n", ca.cre, ca.cim);
//	point.y = 0;
	while (point.y < image->img_h)
	{
		point.x = 0;
		while (point.x < image->img_w)
		{
			pre = 1.5 * (point.x - image->img_w / 2) / (0.5 * zoom_x * image->img_w) + x;
			pim = (point.y - image->img_h / 2) / (0.5 * zoom_y * image->img_h) + y;
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
