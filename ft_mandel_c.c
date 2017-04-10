void	ft_mandelbrot(t_tool *t)
{
	int		x;
	int		y;
	double	zre;
	double	zim;
	double	pre;
	double	pim;
	double	tmp;
	int		i;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			pre = 1.5 * (x - W / 2) / (0.5 * t->zoom * W) + t->move->x;
			pim = 1.0 * (y - H / 2) / (0.5 * t->zoom * H) + t->move->y;
			zim = 0;
			zre = 0;
			i = t->max_iter;
			while (zre * zre + zim * zim < 4 && i > 1)
			{
				tmp = zre * zre - zim * zim + pre;
				zim = 2.0 * zre * zim + pim;
				zre = tmp;
				i--;
			}
			ft_put_pixtoimg(i, t->img, x, y);
			x++;
		}
		y++;
	}
}

for each pixel (Px, Py) on the screen, do:
{
	x0 = scaled x coordinate of pixel (scaled to lie in the Mandelbrot X scale (-2.5, 1))
		y0 = scaled y coordinate of pixel (scaled to lie in the Mandelbrot Y scale (-1, 1))
		x = 0.0
		y = 0.0
		iteration = 0
		max_iteration = 1000
		// Here N=2^8 is chosen as a reasonable bailout radius.
		while ( x*x + y*y < (1 << 16)  AND  iteration < max_iteration ) {
			xtemp = x*x - y*y + x0
				y = 2*x*y + y0
				x = xtemp
				iteration = iteration + 1
		}
	// Used to avoid floating point issues with points inside the set.
	if ( iteration < max_iteration ) {
		// sqrt of inner term removed using log simplification rules.
		log_zn = log( x*x + y*y ) / 2
			nu = log( log_zn / log(2) ) / log(2)
			// Rearranging the potential function.
			// Dividing log_zn by log(2) instead of log(N = 1<<8)
			// because we want the entire palette to range from the
			// center to radius 2, NOT our bailout radius.
			iteration = iteration + 1 - nu
	}
	color1 = palette[floor(iteration)]
		color2 = palette[floor(iteration) + 1]
		// iteration % 1 = fractional part of iteration.
		color = linear_interpolate(color1, color2, iteration % 1)
		plot(Px, Py, color)
}
