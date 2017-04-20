void	get_point_julia(t_image *image, t_point point, t_calc ca)
{
//	int		x;
//	int		y;
	double	x1 = -2.1;
	double	x2 = 0.6;
	double	y1 = -1.2;
	double	y2 = 1.2;
	double	zoom_x;
	double	zoom_y;
	double	c_r;
	double 	c_i;
	double 	z_r;
	double 	z_i;
	double 	tmp;
	int		i;

(void)ca;

	zoom_x = image->img_w / (x2 - x1);
	zoom_y = image->img_h / (y2 - y1);

	point.x = 0;
	while (point.x < image->img_w)
	{
		point.y = 0;
		while (point.y < image->img_h)
		{
			z_r = 0;
			z_i = 0;
			c_r = point.x / zoom_x + x1;
			c_i = point.y / zoom_y + y1;
			i = 0;
			while (z_r *z_r + z_i *z_i < 4 && i <  ITER_MAX_MAN)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}

			if (/*z_r *z_r + z_i *z_i >= 4*/i != ITER_MAX_MAN)
				get_colour(i, image, point, ITER_MAX_MAN);
			point.y++;
		}
		point.x++;
	}
}
