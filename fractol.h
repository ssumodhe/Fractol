/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:47:53 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/04/03 20:47:48 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

# include "libft/libft.h"
# include <mlx.h>

# define WIN_NAME "Smile!!"
# define ITER_MAX 75

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

void				ft_prog(int fd);
void				ft_exit(char *str);

void				create_window(void);

#endif
