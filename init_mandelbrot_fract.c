/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mandelbrot_fract.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 20:12:23 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/05/11 20:22:29 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot(t_fractol f, t_point pc, t_calc cal)
{
	t_image	*img_2;
	int		end = 1;
	int		s_l = 4;
	int		bpp = 32;

	if (!(img_2 = (t_image *)malloc(sizeof(*img_2))))
		ft_exit("error malloc for mandelbrot");
	img_2->img_w = 1280;
	img_2->img_h = 980;
	if (!(img_2->image = mlx_new_image(f.mlx, img_2->img_w, img_2->img_h)))
		ft_exit("error image creation for mandelbrot");
	img_2->img_addr = mlx_get_data_addr(img_2->image, &bpp, &s_l, &end);
	img_2->pc = pc;
	img_2->ca = cal;
	get_point_mandelbrot(img_2, pc, cal);
	put_frame(img_2, pc);
	img_2->f = f;
	mlx_key_hook(f.win_2, ft_mandelbrot_key, img_2);
	mlx_hook(f.win_2, 4, 0, ft_zoom_man, img_2);
	mlx_put_image_to_window(f.mlx, f.win_2, img_2->image, 10, 10);
}

void		init_mandelbrot(t_fractol f, t_point pc)
{
	t_calc	cal_man;

	f.win_2 = mlx_new_window(f.mlx, 1300, 1000, "Mandelbrot's window");
	cal_man.x1 = -2.1;
	cal_man.y1 = -1.2;
	cal_man.x2 = 0.6;
	cal_man.y2 = 1.2;
	ft_mandelbrot(f, pc, cal_man);
}
