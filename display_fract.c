/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_fract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 14:52:32 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/04/13 17:57:49 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
	
void		ft_pixel_put_img(t_image *img, int x, int y, int colour)
{
	int		i;

	if (x >= 0 && y >= 0 && x < img->img_w)
	{
		i = (4 * (x + (y * img->img_w)));
		if (i < (4 * img->img_w * img->img_h) - 4)
		{
			img->img_addr[i + 0] = colour & 0x000000FF;
			img->img_addr[i + 1] = (colour >> 8) & 0x000000FF;
			img->img_addr[i + 2] = (colour >> 16) & 0x000000FF;
			img->img_addr[i + 3] = 0x00;
		}
	}
}

void		ft_choose_side_x(t_point pc, t_image *image)
{
	int		cumul;
	int		i;

	cumul = (pc.dx / 2);
	i = 1;
	while (i <= pc.dx)
	{
		pc.x = pc.x + pc.xinc;
		cumul = cumul + pc.dy;
		if (cumul >= pc.dx)
		{
			cumul = cumul - pc.dx;
			pc.y = pc.y + pc.yinc;
		}
		ft_pixel_put_img(image, pc.x, pc.y, pc.colour);
		i++;
	}
}

void		ft_choose_side_y(t_point pc, t_image *image)
{
	int		cumul;
	int		i;

	cumul = (pc.dy / 2);
	i = 1;
	while (i <= pc.dy)
	{
		pc.y = pc.y + pc.yinc;
		cumul = cumul + pc.dx;
		if (cumul >= pc.dy)
		{
			cumul = cumul - pc.dy;
			pc.x = pc.x + pc.xinc;
		}
		ft_pixel_put_img(image, pc.x, pc.y, pc.colour);
		i++;
	}
}

void		ft_drawline_img(t_image *image, t_point pc)
{
	pc.x = pc.x1;
	pc.y = pc.y1;
	pc.dx = pc.x2 - pc.x1;
	pc.dy = pc.y2 - pc.y1;
	pc.xinc = (pc.dx > 0) ? 1 : -1;
	pc.yinc = (pc.dy > 0) ? 1 : -1;
	pc.dx = (pc.dx < 0) ? -pc.dx : pc.dx;
	pc.dy = (pc.dy < 0) ? -pc.dy : pc.dy;
	ft_pixel_put_img(image, pc.x, pc.y, pc.colour);
	if (pc.dx > pc.dy)
		ft_choose_side_x(pc, image);
	else
		ft_choose_side_y(pc, image);
}

