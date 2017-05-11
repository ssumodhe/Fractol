/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 22:43:12 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/05/11 20:19:19 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_kitty(t_fractol f, t_point pc)
{
	t_image	*img_3;
	int		end = 1;
	int		s_l = 4;
	int		bpp = 32;

	f.win_3 = mlx_new_window(f.mlx, 1800, 500, "Kitty's window");
	if (!(img_3 = (t_image *)malloc(sizeof(*img_3))))
		ft_exit("error malloc for kitty");
	img_3->img_w = 1780;
	img_3->img_h = 480;
	if (!(img_3->image = mlx_new_image(f.mlx, img_3->img_w, img_3->img_h)))
		ft_exit("error image creation for kitty");
	img_3->img_addr = mlx_get_data_addr(img_3->image, &bpp, &s_l, &end);
	put_frame(img_3, pc);
	get_point_kitty(img_3, pc);
	mlx_key_hook(f.win_3, ft_kitty_key, img_3);
	mlx_put_image_to_window(f.mlx, f.win_3, img_3->image, 10, 10);
}

void	ft_directionkey(int keycode,t_image *image)
{
   	if (keycode == 123) // fleche gauche
	{
		image->ca.x1 = image->ca.x1 + 0.01;
		image->ca.x2 = image->ca.x2 + 0.01;
	}
	else if (keycode == 124) // fleche droite
	{
		image->ca.x1 = image->ca.x1 - 0.01;
		image->ca.x2 = image->ca.x2 - 0.01;
	}
	else if (keycode == 126) // fleche haut
	{
		image->ca.y1 = image->ca.y1 + 0.01;
		image->ca.y2 = image->ca.y2 + 0.01;
	}
	else if (keycode == 125) // fleche bas
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
	if (check == 1 || check == 2 || check == 3 ||  check == 5 || check == 6 || \
			check == 9 || check == 14 || check == 15 || check == 18 || check == 27 \
			|| check == 41 || check == 45 || check == 54 || check == 81)
		init_julia(f, pc);
	if (check == 4 || check == 8 || check == 9 || check == 12 || check == 5 || \
			check == 17 || check == 18 || check == 44 || check == 45 || check == 57 \
			|| check == 84 || check == 21 || check == 30 || check == 6)
		init_mandelbrot(f, pc);
	
	if (check == 13 || check == 26 || check == 39 || check == 14 || check == 15\
			|| check == 17 || check == 18  || check == 27 || check == 53 || \
			check == 54	|| check == 57 || check == 93 || check == 21 || check == 30)
	{
		ft_kitty(f, pc);
	}
	mlx_loop(f.mlx);
}
