/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_fract.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:32:50 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/04/12 15:46:41 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
				//ft_pixel_put_img(image, point.x, point.y, i);
		}
		point.y++;
	}
}

void	ft_mandelbrot(void)
{
	t_fractol	fractol;
	t_image		*image;
	t_point		point;
	int	end;
	int	s_l;
	int bpp;

	fractol.mlx = mlx_init();
	fractol.win_1 = mlx_new_window(fractol.mlx, 1500, 1020, WIN_NAME);

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

	point.y = 0;
	get_point_mandelbrot(image, point);
	put_frame(image, point);
	mlx_put_image_to_window(fractol.mlx, fractol.win_1, fractol.image, \
			10, 10);
	mlx_loop(fractol.mlx);
}
