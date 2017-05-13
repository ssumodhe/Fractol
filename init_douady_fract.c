/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_douady_fract.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 22:18:48 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/05/14 00:15:34 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_douady(t_fractol f, t_point pc, t_calc cal)
{
	t_image	*img_3;
	int		end;
	int		s_l;
	int		bpp;

	if (!(img_3 = (t_image *)malloc(sizeof(*img_3))))
		ft_exit("error malloc for douady");
	img_3->img_w = 1480;
	img_3->img_h = 1000;
	if (!(img_3->image = mlx_new_image(f.mlx, img_3->img_w, img_3->img_h)))
		ft_exit("error image creation for douady");
	end = 1;
	s_l = 4;
	bpp = 32;
	img_3->img_addr = mlx_get_data_addr(img_3->image, &bpp, &s_l, &end);
	img_3->pc = pc;
	img_3->ca = cal;
	get_point_douady(img_3, pc, cal);
	put_frame(img_3, pc);
	img_3->f = f;
	mlx_key_hook(f.win_3, ft_douady_key, img_3);
	mlx_hook(f.win_3, 4, 0, ft_zoom_dou, img_3);
	mlx_put_image_to_window(f.mlx, f.win_3, img_3->image, 10, 10);
}

void		init_douady(t_fractol f, t_point pc)
{
	t_calc	cal_dou;

	f.win_3 = mlx_new_window(f.mlx, 1500, 1020, "Douady's window");
	cal_dou.cre = 0.291757;
	cal_dou.cim = 0.571200;
	cal_dou.x1 = -1.7;
	cal_dou.y1 = -1.2;
	cal_dou.x2 = 1.7;
	cal_dou.y2 = 1.2;
	ft_douady(f, pc, cal_dou);
}
