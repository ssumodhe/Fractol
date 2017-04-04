/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:47:53 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/04/04 16:49:00 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

# include "libft/libft.h"
# include <mlx.h>

# define WIN_NAME "Smile!!"
# define ITER_MAX 50

typedef	struct		s_fractol
{
	void	*mlx;
	void	*win;
	void	*image;
}					t_fractol;

typedef	struct		s_image
{
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
	float		x; //int?
	float		y; //int?
	float		dx;
	float		dy;
	float		xinc;
	float		yinc;
}					t_point;

/*
** parsing_fract.c
*/
int					checkfile(char *str);
int					pick_fract(int check);

/*
** mandelbrot_fract.c
*/
void				ft_mandelbrot(void);
void				ft_drawfractal(t_image *image, t_point point);
void				get_point(t_image *image, t_point point, float zoom_x, \
						float zoom_y);
void				ft_drawline_img(t_image *image, t_point pc);
void				ft_choose_side_y(t_point pc, t_image *image);
void				ft_choose_side_x(t_point pc, t_image *image);
void				ft_pixel_put_img(t_image *img, int x, int y,int colour);

#endif
