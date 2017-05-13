/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:47:53 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/05/14 00:02:00 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>

# define WIN_NAME "Smile!!"
# define ITER_MAX_MAN 150
# define ITER_MAX_JU 100
# define ITER_MAX_DOU 100

typedef struct		s_cal_col
{
	double		c;
	double		l;
	double		s;
	double		x;
	double		h;
	double		m;
	double		radian;
	int			i;
}					t_cal_col;

typedef struct		s_colours
{
	int		red;
	int		green;
	int		blue;
}					t_colours;

typedef struct		s_calc
{
	double		cre;
	double		cim;
	double		zoom_x;
	double		zoom_y;
	double		x1;
	double		y1;
	double		x2;
	double		y2;
}					t_calc;

typedef	struct		s_fractol
{
	void	*mlx;
	void	*win_1;
	void	*win_2;
	void	*win_3;
	void	*image;
}					t_fractol;

typedef	struct		s_point
{
	float		x1;
	float		y1;
	float		x2;
	float		y2;
	float		colour;
	double		x;
	double		y;
	float		dx;
	float		dy;
	float		xinc;
	float		yinc;
}					t_point;

typedef	struct		s_image
{
	void		*image;
	float		img_w;
	float		img_h;
	char		*img_addr;
	int			status_mouse;
	t_fractol	f;
	t_point		pc;
	t_calc		ca;
}					t_image;

/*
** main_fract.c
*/
int					checkfile(char *str);

/*
** pick_fract.c
*/
void				pick_fract(int check);
void				zoom_init(t_image *image, int x, int y, double zoom);
void				ft_directionkey(int keycode, t_image *image);

/*
** display_fract.c
*/
void				ft_drawline_img(t_image *image, t_point pc);
void				ft_choose_side_y(t_point pc, t_image *image);
void				ft_choose_side_x(t_point pc, t_image *image);
void				ft_pixel_put_img(t_image *img, int x, int y, int colour);

/*
** display_2_fract.c
*/
t_colours			colours_2(double h, double c, double x);
t_colours			colours_1(double h, double c, double x);
void				get_colour(int colour, t_image *img, t_point point, \
						double iter_max);
void				put_frame(t_image *image, t_point point);

/*
** mandelbrot_fract.c
*/
void				get_point_mandelbrot(t_image *image, t_point point, \
						t_calc ca);
int					ft_draw_man(t_point point, t_calc ca);
int					ft_mandelbrot_key(int keycode, t_image *image);
int					ft_zoom_man(int click, int x, int y, t_image *image);

/*
** init_mandelbrot_fract.c
*/
void				init_mandelbrot(t_fractol f, t_point pc);
void				ft_mandelbrot(t_fractol f, t_point pc, t_calc cal);

/*
** julia_fract.c
*/
void				get_point_julia(t_image *image, t_point point, t_calc ca);
int					ft_draw_ju(t_point point, t_calc ca);
int					ft_julia_key(int keycode, t_image *image);
int					ft_hook(int x, int y, t_image *image);
int					ft_zoom_ju(int click, int x, int y, t_image *image);

/*
** init_julia_fract.c
*/
void				init_julia(t_fractol f, t_point pc);
t_image				*ft_julia(t_fractol f, t_point pc, t_calc cal);
void				ft_destroy_create_julia(t_image *image);

/*
** douady_fract.c
*/
void				get_point_douady(t_image *image, t_point point, t_calc ca);
int					ft_draw_dou(t_point point, t_calc ca);
int					ft_douady_key(int keycode, t_image *image);
int					ft_zoom_dou(int click, int x, int y, t_image *image);

/*
** init_douady_fract.c
*/
void				init_douady(t_fractol f, t_point pc);
void				ft_douady(t_fractol f, t_point pc, t_calc cal);

#endif
