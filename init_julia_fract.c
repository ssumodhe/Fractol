/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_julia_fract.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:39:55 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/05/11 20:23:16 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia(t_fractol f, t_point pc, t_calc cal)
{
	t_image	*img_1;
	int		end = 1;
	int		s_l = 4;
	int		bpp = 32;

	if (!(img_1 = (t_image *)malloc(sizeof(*img_1))))
		ft_exit("error malloc for julia");
	img_1->img_w = 1480;
	img_1->img_h = 1000;
	if (!(img_1->image = mlx_new_image(f.mlx, img_1->img_w, img_1->img_h)))
		ft_exit("error image creation for julia");
	img_1->img_addr = mlx_get_data_addr(img_1->image, &bpp, &s_l, &end);
	img_1->pc = pc;
	img_1->ca = cal;
	get_point_julia(img_1, pc, cal);
	put_frame(img_1, pc);
	img_1->f = f;
	mlx_key_hook(f.win_1, ft_julia_key, img_1);
	mlx_hook(f.win_1, 4, 0, ft_zoom_ju, img_1);
	mlx_put_image_to_window(f.mlx, f.win_1, img_1->image, 10, 10);
}

void		init_julia(t_fractol f, t_point pc)
{
	t_calc	cal_ju;

	f.win_1 = mlx_new_window(f.mlx, 1500, 1020, "Julia's window");
	cal_ju.cre = -0.7;
	cal_ju.cim = 0.27015;
	cal_ju.x1 = -1.7;
	cal_ju.y1 = -1.2;
	cal_ju.x2 = 1.7;
	cal_ju.y2 = 1.2;
	ft_julia(f, pc, cal_ju);
}
