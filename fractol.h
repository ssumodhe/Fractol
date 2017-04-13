/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:47:53 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/04/13 18:10:35 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>

# define WIN_NAME "Smile!!"
# define ITER_MAX_MAN 142
# define ITER_MAX_JU 200
# define ITER_MAX_KITZ 10

typedef struct		s_circle
{
	int		r;
}					t_circle;

typedef	struct		s_fractol
{
	void	*mlx;
	void	*win_1;
	void	*win_2;
	void	*win_3;
	void	*image;
}					t_fractol;

typedef	struct		s_image
{
	void	*image;
	float		img_w;
	float		img_h;
	char	*img_addr;
}					t_image;

typedef	struct		s_point
{
	float		x1;
	float		y1;
	float		x2;
	float		y2;
	float		colour;
	double		x; //int?
	double		y; //int?
	float		dx;
	float		dy;
	float		xinc;
	float		yinc;
}					t_point;

/*
** parsing_fract.c
*/
int					checkfile(char *str);
void					pick_fract(int check);

/*
** display_fract.c
*/
void				ft_drawline_img(t_image *image, t_point pc);
void				ft_choose_side_y(t_point pc, t_image *image);
void				ft_choose_side_x(t_point pc, t_image *image);
void				ft_pixel_put_img(t_image *img, int x, int y,int colour);

/*
** display_2_fract.c
*/
void				get_colour(int colour, t_image *img, t_point point, double iter_max);
void				put_frame(t_image *image, t_point point);

/*
** mandelbrot_fract.c
*/

void				ft_mandelbrot(void);
void				get_point_mandelbrot(t_image *image, t_point point);

/*
** julia_fract.c
*/
void				ft_julia(void);
void				get_point_julia(t_image *image, t_point point);

/*
** kitty_fract.c
*/
void				ft_kitty(void);
void				get_point_kitty(t_image *image, t_point point);

#endif
