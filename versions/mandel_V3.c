/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_fract.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:32:50 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/04/12 12:24:18 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
	
void		ft_pixel_put_img(t_image *img, int x, int y, int colour)
{
	int		i;

	if (x >= 0 && y >= 0 && x < img->img_w)
	{
		i = (4 * (x + (y * img->img_w)));
		if (i < (4 * img->img_w * img->img_h) - 4)
		{
			img->img_addr[i + 0] = colour & 0x000000FF;
			img->img_addr[i + 1] = (colour >> 8) & 0x000000FF;
			img->img_addr[i + 2] = (colour >> 16) & 0x000000FF;
			img->img_addr[i + 3] = 0x00;
		}
	}
}

void		ft_choose_side_x(t_point pc, t_image *image)
{
	int		cumul;
	int		i;

	cumul = (pc.dx / 2);
	i = 1;
	while (i <= pc.dx)
	{
		pc.x = pc.x + pc.xinc;
		cumul = cumul + pc.dy;
		if (cumul >= pc.dx)
		{
			cumul = cumul - pc.dx;
			pc.y = pc.y + pc.yinc;
		}
		ft_pixel_put_img(image, pc.x, pc.y, pc.colour);
		i++;
	}
}

void		ft_choose_side_y(t_point pc, t_image *image)
{
	int		cumul;
	int		i;

	cumul = (pc.dy / 2);
	i = 1;
	while (i <= pc.dy)
	{
		pc.y = pc.y + pc.yinc;
		cumul = cumul + pc.dx;
		if (cumul >= pc.dy)
		{
			cumul = cumul - pc.dy;
			pc.x = pc.x + pc.xinc;
		}
		ft_pixel_put_img(image, pc.x, pc.y, pc.colour);
		i++;
	}
}

void		ft_drawline_img(t_image *image, t_point pc)
{
	pc.x = pc.x1;
	pc.y = pc.y1;
	pc.dx = pc.x2 - pc.x1;
	pc.dy = pc.y2 - pc.y1;
	pc.xinc = (pc.dx > 0) ? 1 : -1;
	pc.yinc = (pc.dy > 0) ? 1 : -1;
	pc.dx = (pc.dx < 0) ? -pc.dx : pc.dx;
	pc.dy = (pc.dy < 0) ? -pc.dy : pc.dy;
	ft_pixel_put_img(image, pc.x, pc.y, pc.colour);
	if (pc.dx > pc.dy)
		ft_choose_side_x(pc, image);
	else
		ft_choose_side_y(pc, image);
}

void		get_colour(int colour, t_image *img, t_point point)
{
	double		c;
	double		l;
	double		s;
	double		x;
	double		h;
	double		m;
	double		radian;
	int			red;
	int			blue;
	int			green;
	int			i;

	h = (colour * 360) / ITER_MAX;
	l = 0.5;
	s = 1;

	c = (1 - fabs((2*l) - 1)) * s;
	radian = 60 * M_PI / 180;
	x = c * (1 - fabs(((h / cos(radian)) / 2) - 1));
	m = l - (c / 2);
	if (h >= 0 && h < 60)
	{
		red = c;
		green = x;
		blue = 0;
	}
	if (h >= 60 && h < 120)
	{
		red = x;
		green = c;
		blue = 0;
	}
	if (h >= 120 && h < 180)
	{
		red = 0;
		green = c;
		blue = x;
	}
	if (h >= 180 && h < 240)
	{
		red = 0;
		green = x;
		blue = c;
	}
	if (h >= 240 && h < 300)
	{
		red = x;
		green = 0;
		blue = c;
	}
	if (h >= 300 && h < 360)
	{
		red = c;
		green = 0;
		blue = x;
	}

	red = (red + m) * 255;
	green = (green + m) * 255;
	blue = (blue + m) * 255;

	if (point.x >= 0 && point.y >= 0 && point.x < img->img_w)
	{
		i = (4 * (point.x + (point.y * img->img_w)));
		if (i < (4 * img->img_w * img->img_h) - 4)
		{
			img->img_addr[i + 0] = blue;
			img->img_addr[i + 1] = green;
			img->img_addr[i + 2] = red;
			img->img_addr[i + 3] = 0x00;
		}
	}

}

void	get_point(t_image *image, t_point point)
{
	int		x;
	int		y;
	double	zre;
	double	zim;
	double	pre;
	double	pim;
	double	tmp;
	double	zoom_x;
	double	zoom_y;
	int		i;

	x = 0;
	y = 0;
	zoom_x = 1;
	zoom_y = 1;
//	zoom_x = image->img_w / (point.x2 - point.x1);
//	zoom_y = image->img_h / (point.y2 - point.y1);
	point.y = 0;
	while (point.y < image->img_h)
	{
		point.x = 0;
		while (point.x < image->img_w)
		{
			pre = 1.5 * (point.x - image->img_w / 2) / (0.5 * zoom_x * image->img_w) + x; 
			pim = 1.0 * (point.y - image->img_h / 2) / (0.5 * zoom_y * image->img_h) + y;
			zim = 0;
			zre = 0;
			i = ITER_MAX;
			while (zre * zre + zim * zim < 4 && i > 1)
			{
				tmp = zre * zre - zim * zim + pre;
				zim = 2.0 * zre * zim + pim;
				zre = tmp;
				i--;
			}

			if (zre * zre + zim * zim >= 4)
			{
				get_colour(i, image, point);
			}
			else
				ft_pixel_put_img(image, point.x, point.y, i);
			point.x++;
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
	fractol.win = mlx_new_window(fractol.mlx, 1020, 1020, WIN_NAME);

	if (!(image = (t_image *)malloc(sizeof(*image))))
		ft_exit("error malloc t_image *image");
	image->img_w = 1000;
	image->img_h = 1000;

	if (!(fractol.image = mlx_new_image(fractol.mlx, image->img_w, image->img_h)))
		ft_exit("error image creation");
	end = 1;
	s_l = 4;
	bpp = 32;
	image->img_addr = mlx_get_data_addr(fractol.image, &bpp, &s_l, &end);

	point.colour = 0x00FFFFFF;
	get_point(image, point);

/*
	point.x1 = -2.1;
	point.y1 = 0.6;
	point.x2 = -1.2;
	point.y2 = 1.2;
	point.x1 = -2.5;
	point.y1 = -1.5;
	point.x2 = 1.5;
	point.y2 = 1.5;
	point.colour = 0x0000868B;
	ft_drawfractal(image, point);
*/

/*
** Frame.
*/
	point.x1 = 0;
	point.y1 = 0;
	point.x2 = image->img_w - 1;
	point.y2 = 0;
	point.colour = 0x0000868B;
	ft_drawline_img(image, point);
	point.x1 = image->img_w - 1;
	point.y1 = 0;
	point.x2 = image->img_w - 1;
	point.y2 = image->img_h - 1;
	point.colour = 0x0000868B;
	ft_drawline_img(image, point);
	point.x1 = image->img_w - 1;
	point.y1 = image->img_h - 1;
	point.x2 = 0;
	point.y2 = image->img_h - 1;
	point.colour = 0x0000868B;
	ft_drawline_img(image, point);
	point.x1 = 0;
	point.y1 = image->img_h - 1;
	point.x2 = 0;
	point.y2 = 0;
	point.colour = 0x0000868B;
	ft_drawline_img(image, point);

	mlx_put_image_to_window(fractol.mlx, fractol.win, fractol.image, \
			10, 10);
	mlx_loop(fractol.mlx);
}
