/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 13:00:07 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/04/12 16:00:09 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_point_julia(t_image *image, t_point point)
{
	double	cre;
	double	cim;
	double	pre;
	double	pim;
	double	tmp;
	double	zoom_x = 1;
	double	zoom_y = 1;
	double	x = 0;
	double	y = 0;
	int		i;

	cre = -0.7;
	cim = 0.27015;
	
	point.y = 0;
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
				pre = pre * pre - pim * pim + cre;
				pim = 2 * tmp * pim + cim;
				i++;
			}
			point.x++;
			if ((pre * pre + pim * pim) >= 4)
				get_colour(i, image, point, ITER_MAX_JU);
				//ft_pixel_put_img(image, point.x, point.y, i);
		}
		point.y++;
	}
	
}

void	ft_julia(void)
{
	t_fractol	fractol;
	t_image		*image;
	t_point		point;
	int	end;
	int	s_l;
	int bpp;

	fractol.mlx = mlx_init();
	fractol.win_2 = mlx_new_window(fractol.mlx, 1500, 1020, WIN_NAME);

	if (!(image = (t_image *)malloc(sizeof(*image))))
		ft_exit("error malloc t_image *image");
	image->img_w = 1480;
	image->img_h = 1000;

	if (!(fractol.image = mlx_new_image(fractol.mlx, image->img_w, image->img_h)))
		ft_exit("error image creation");
	end = 1;
	s_l = 4;
	bpp = 32;
	image->img_addr = mlx_get_data_addr(fractol.image, &bpp, &s_l, &end);

	point.colour = 0x00FFFFFF;
	get_point_julia(image, point);
	put_frame(image, point);
	mlx_put_image_to_window(fractol.mlx, fractol.win_2, fractol.image, \
			10, 10);
	mlx_loop(fractol.mlx);
}
