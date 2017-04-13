/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kitty_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:52:59 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/04/12 21:33:44 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_circle(t_image *image, t_point point, t_circle circle)
{
	double		x;
	double		y;

	y = -circle.r;
	while (y < (circle.r + 1))
	{
		x = -circle.r;
		while (x < (circle.r + 1))
		{
				if (fabs((x * x) + (y * y) - (circle.r * circle.r)) <= (circle.r / 2))
					ft_pixel_put_img(image, point.x + x, point.y + y, point.colour);
			x = x + 0.5;
		}
		y = y + 0.5;
	}
}

void	get_point_kitty(t_image *image, t_point point)
{
	t_circle 	circle;
	int			i;

	point.colour = 0x0099FF;
	point.x = image->img_w / 2;
	point.y = image->img_h / 2;
	circle.r = 300;
	i = 0;
	draw_circle(image, point, circle);
	while (i < ITER_MAX_KITZ && circle.r > 2)
	{
		point.x = point.x + (circle.r * 0.67);
		circle.r = circle.r * 0.67;
		draw_circle(image, point, circle);
		i++;
	}
}

void	ft_kitty(void)
{
	t_fractol	fractol;
	t_image		*image;
	t_point		point;
	int	end;
	int	s_l;
	int bpp;

	fractol.mlx = mlx_init();
	fractol.win_3 = mlx_new_window(fractol.mlx, 1500, 1020, WIN_NAME);

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
	get_point_kitty(image, point);
	put_frame(image, point);
	mlx_put_image_to_window(fractol.mlx, fractol.win_3, fractol.image, \
			10, 10);
	mlx_loop(fractol.mlx);
}
