/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 22:43:12 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/04/20 16:25:19 by ssumodhe         ###   ########.fr       */
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
void	ft_mandelbrot(t_fractol f, t_point pc)
{
	t_image	*img_2;
	int		end = 1;
	int		s_l = 4;
	int		bpp = 32;

	f.win_2 = mlx_new_window(f.mlx, 1300, 820, "Mandelbrot's window");
	if (!(img_2 = (t_image *)malloc(sizeof(*img_2))))
		ft_exit("error malloc for mandelbrot");
	img_2->img_w = 1280;
	img_2->img_h = 800;
	if (!(img_2->image = mlx_new_image(f.mlx, img_2->img_w, img_2->img_h)))
		ft_exit("error image creation for mandelbrot");
	img_2->img_addr = mlx_get_data_addr(img_2->image, &bpp, &s_l, &end);

	get_point_mandelbrot(img_2, pc);
	put_frame(img_2, pc);

	mlx_key_hook(f.win_2, ft_mandelbrot_key, img_2);
	mlx_put_image_to_window(f.mlx, f.win_2, img_2->image, 10, 10);
}

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
	mlx_put_image_to_window(f.mlx, f.win_1, img_1->image, 10, 10);
}

void	pick_fract(int check)
{
	t_fractol	f;
	t_point		pc;
	t_calc	cal;

	f.mlx = mlx_init();
	pc.y = 0;
	if (check == 1 || check == 2 || check == 3 ||  check == 5 || check == 6 || \
			check == 9 || check == 14 || check == 15 || check == 18 || check == 27 \
			|| check == 41 || check == 45 || check == 54 || check == 81)
	{
	f.win_1 = mlx_new_window(f.mlx, 1500, 1020, "Julia's window");
		cal.cre = -0.7;
		cal.cim = 0.27015;
		cal.x1 = -1.7;
		cal.y1 = -1.2;
		cal.x2 = 1.7;
		cal.y2 = 1.2;
		ft_julia(f, pc, cal);
	}
	if (check == 4 || check == 8 || check == 9 || check == 12 || check == 5 || \
			check == 17 || check == 18 || check == 44 || check == 45 || check == 57 \
			|| check == 84 || check == 21 || check == 30 || check == 6)
	{
		ft_mandelbrot(f, pc);
	}
	if (check == 13 || check == 26 || check == 39 || check == 14 || check == 15\
			|| check == 17 || check == 18  || check == 27 || check == 53 || \
			check == 54	|| check == 57 || check == 93 || check == 21 || check == 30)
	{
		ft_kitty(f, pc);
	}
	mlx_loop(f.mlx);
}
