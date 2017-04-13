/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_fract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:06:15 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/04/13 19:11:59 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
int		pick_fract(int check)
{
		{
		printf("to do : julia\n");
	//	ft_julia();
	}
	{
		printf("to do : mandelbrot\n");
	//	ft_mandelbrot();
	}
	{
		printf("to do : kitty\n");
	//	ft_kitty();
	}
	if (check > 7)
		return (1);
	return (0);
}*/

void	pick_fract(int check)
{
	t_fractol	f;
	t_image	*img_1;
	t_image	*img_2;
	t_image	*img_3;
	t_point	pc;
	int		end = 1;
	int		s_l = 4;
	int		bpp = 32;

	f.mlx = mlx_init();

	pc.colour = 0x00FFFFFF;
	if (check == 1 || check == 3 || check == 5 || check == 7 || check == 9 ||\
			check == 11 || check == 13)
	{
		f.win_1 = mlx_new_window(f.mlx, 1500, 1020, "Julia's window");
		if (!(img_1 = (t_image *)malloc(sizeof(*img_1))))
			ft_exit("error malloc for julia");
		img_1->img_w = 1480;
		img_1->img_h = 1000;
		if (!(img_1->image = mlx_new_image(f.mlx, img_1->img_w, img_1->img_h)))
			ft_exit("error image creation for julia");
		img_1->img_addr = mlx_get_data_addr(img_1->image, &bpp, &s_l, &end);
	
		get_point_julia(img_1, pc);
		put_frame(img_1, pc);
	
		mlx_put_image_to_window(f.mlx, f.win_1, img_1->image, 10, 10);
	}

	if (check == 2 || check == 3 || check == 6 || check == 7 || check == 10 ||\
			check == 11 || check == 14)
	{
		f.win_2 = mlx_new_window(f.mlx, 1500, 1020, "Mandelbrot's window");
		if (!(img_2 = (t_image *)malloc(sizeof(*img_2))))
			ft_exit("error malloc for mandelbrot");
		img_2->img_w = 1480;
		img_2->img_h = 1000;
		if (!(img_2->image = mlx_new_image(f.mlx, img_2->img_w, img_2->img_h)))
			ft_exit("error image creation for mandelbrot");
		img_2->img_addr = mlx_get_data_addr(img_2->image, &bpp, &s_l, &end);
	
		get_point_mandelbrot(img_2, pc);
		put_frame(img_2, pc);
	
		mlx_put_image_to_window(f.mlx, f.win_2, img_2->image, 10, 10);
	}

	if (check == 4 || check == 5 || check == 6 || check == 7 || check == 12 ||\
			check == 13 || check == 14)
	{
		f.win_3 = mlx_new_window(f.mlx, 400, 400, "Kitty's window");
		if (!(img_3 = (t_image *)malloc(sizeof(*img_3))))
			ft_exit("error malloc for kitty");
		img_3->img_w = 380;
		img_3->img_h = 380;
		if (!(img_3->image = mlx_new_image(f.mlx, img_3->img_w, img_3->img_h)))
			ft_exit("error image creation for kitty");
		img_3->img_addr = mlx_get_data_addr(img_3->image, &bpp, &s_l, &end);
	
		put_frame(img_3, pc);
	
		mlx_put_image_to_window(f.mlx, f.win_3, img_3->image, 10, 10);
	}

	mlx_loop(f.mlx);
}
