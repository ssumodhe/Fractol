#include "fractol.h"

void		get_colour(int colour, t_image *img, t_point point, double iter_max)
{
	double		c;
	double		l;
	double		s;
	double		x;
	double		h;
	double		m;
	double		radian;
	int			red;
	int			blue;
	int			green;
	int			i;

	h = (colour * 360) / iter_max;
	l = 0.5;
	s = 1;

	c = (1 - fabs((2*l) - 1)) * s;
	radian = 60 * M_PI / 180;
	x = c * (1 - fabs(((h / cos(radian)) / 2) - 1));
	m = l - (c / 2);
	if (h >= 0 && h < 60)
	{
		red = c;
		green = x;
		blue = 0;
	}
	if (h >= 60 && h < 120)
	{
		red = x;
		green = c;
		blue = 0;
	}
	if (h >= 120 && h < 180)
	{
		red = 0;
		green = c;
		blue = x;
	}
	if (h >= 180 && h < 240)
	{
		red = 0;
		green = x;
		blue = c;
	}
	if (h >= 240 && h < 300)
	{
		red = x;
		green = 0;
		blue = c;
	}
	if (h >= 300 && h < 360)
	{
		red = c;
		green = 0;
		blue = x;
	}

	red = (red + m) * 255;
	green = (green + m) * 255;
	blue = (blue + m) * 255;

	if (point.x >= 0 && point.y >= 0 && point.x < img->img_w)
	{
		i = (4 * (point.x + (point.y * img->img_w)));
		if (i < (4 * img->img_w * img->img_h) - 4)
		{
			img->img_addr[i + 0] = blue;
			img->img_addr[i + 1] = green;
			img->img_addr[i + 2] = red;
			img->img_addr[i + 3] = 0x00;
		}
	}

}

void	put_frame(t_image *image, t_point point)
{
	point.colour = 0x00FFFFFF;
	point.x1 = 0;
	point.y1 = 0;
	point.x2 = image->img_w - 1;
	point.y2 = 0;
	ft_drawline_img(image, point);
	point.x1 = image->img_w - 1;
	point.y1 = 0;
	point.x2 = image->img_w - 1;
	point.y2 = image->img_h - 1;
	ft_drawline_img(image, point);
	point.x1 = image->img_w - 1;
	point.y1 = image->img_h - 1;
	point.x2 = 0;
	point.y2 = image->img_h - 1;
	ft_drawline_img(image, point);
	point.x1 = 0;
	point.y1 = image->img_h - 1;
	point.x2 = 0;
	point.y2 = 0;
	ft_drawline_img(image, point);
}
