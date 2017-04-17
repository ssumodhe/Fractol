	int		r = 100;
	double		x;
	double		y;

	point.colour = 0x0099FF;
	point.x = 500;
	point.y = 500;
	y = -r;
	while (y < (r + 1))
	{
		x = -r;
		while (x < (r + 1))
		{
			if (fabs((x * x) + (y * y) - (r * r)) <= (r / 2))
				ft_pixel_put_img(image, point.x + x, point.y + y, point.colour);
			x = x + 0.5;
		}
		y = y + 0.5;
	}
	point.colour = 0x00FFFFFF;
	point.x = 725;
	point.y = 500;
	y = -r;
	while (y < (r + 1))
	{
		x = -r;
		while (x < (r + 1))
		{
			if (fabs((x * x) + (y * y) - (r * r)) <= (r / 2))
				ft_pixel_put_img(image, point.x + x, point.y + y, point.colour);
			x = x + 0.1;
		}
		y = y + 0.1;
	}
point.colour = 0x00FF0000;
	point.x = 950;
	point.y = 500;
	y = -r;
	while (y < (r + 1))
	{
		x = -r;
		while (x < (r + 1))
		{
			if (fabs((x * x) + (y * y) - (r * r)) <= (r / 2))
				ft_pixel_put_img(image, point.x + x, point.y + y, point.colour);
			x = x + 0.1;
		}
		y = y + 0.1;
	}
point.colour = 0xFFCC33;
	point.x = 625;
	point.y = 625;
	y = -r;
	while (y < (r + 1))
	{
		x = -r;
		while (x < (r + 1))
		{
			if (fabs((x * x) + (y * y) - (r * r)) <= (r / 2))
				ft_pixel_put_img(image, point.x + x, point.y + y, point.colour);
			x = x + 0.1;
		}
		y = y + 0.1;
	}
point.colour = 0x00FF00;
	point.x = 850;
	point.y = 625;
	y = -r;
	while (y < (r + 1))
	{
		x = -r;
		while (x < (r + 1))
		{
			if (fabs((x * x) + (y * y) - (r * r)) <= (r / 2))
				ft_pixel_put_img(image, point.x + x, point.y + y, point.colour);
			x = x + 0.1;
		}
		y = y + 0.1;
	}

