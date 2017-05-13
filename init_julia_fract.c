/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_julia_fract.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:39:55 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/05/14 00:10:34 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_destroy_create_julia(t_image *image)
{
	int		end;
	int		s_l;
	int		bpp;

	mlx_destroy_image(image->f.mlx, image->image);
	if (!(image->image = mlx_new_image(image->f.mlx, image->img_w, \
					image->img_h)))
		ft_exit("error image creation for julia");
	end = 1;
	s_l = 4;
	bpp = 32;
	image->img_addr = mlx_get_data_addr(image->image, &bpp, &s_l, &end);
	get_point_julia(image, image->pc, image->ca);
	put_frame(image, image->pc);
	mlx_put_image_to_window(image->f.mlx, image->f.win_1, image->image, 10, 10);
}

t_image		*ft_julia(t_fractol f, t_point pc, t_calc cal)
{
	t_image	*img_1;
	int		end;
	int		s_l;
	int		bpp;

	if (!(img_1 = (t_image *)malloc(sizeof(*img_1))))
		ft_exit("error malloc for julia");
	img_1->img_w = 1480;
	img_1->img_h = 1000;
	img_1->status_mouse = 0;
	if (!(img_1->image = mlx_new_image(f.mlx, img_1->img_w, img_1->img_h)))
		ft_exit("error image creation for julia");
	end = 1;
	s_l = 4;
	bpp = 32;
	img_1->img_addr = mlx_get_data_addr(img_1->image, &bpp, &s_l, &end);
	img_1->pc = pc;
	img_1->ca = cal;
	get_point_julia(img_1, pc, cal);
	put_frame(img_1, pc);
	img_1->f = f;
	mlx_put_image_to_window(f.mlx, f.win_1, img_1->image, 10, 10);
	return (img_1);
}

void		init_julia(t_fractol f, t_point pc)
{
	t_calc	cal_ju;
	t_image	*img_1;

	f.win_1 = mlx_new_window(f.mlx, 1500, 1020, "Julia's window");
	cal_ju.cre = -0.7;
	cal_ju.cim = 0.27015;
	cal_ju.x1 = -1.7;
	cal_ju.y1 = -1.2;
	cal_ju.x2 = 1.7;
	cal_ju.y2 = 1.2;
	img_1 = ft_julia(f, pc, cal_ju);
	mlx_key_hook(f.win_1, ft_julia_key, img_1);
	mlx_hook(f.win_1, 4, 0, ft_zoom_ju, img_1);
	mlx_hook(f.win_1, 6, 0, ft_hook, img_1);
}
