/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:47:16 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/04/13 19:12:02 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		checkfile(char *str)
{
	int		num;

	num = 0;
	if (ft_strcmp("julia", str) == 0)
		num = 1;
	else if (ft_strcmp("mandelbrot", str) == 0)
		num = 2;
	else if (ft_strcmp("kitty", str) == 0)
		num = 4;
	else
		num = 8;
	return (num);
}

int		main(int argc, char **argv)
{
	int		i;
	int		check;

	if (argc != 4 && argc != 3 && argc != 2)
		ft_exit("usage: ./fractol [mandelbrot | julia | kitty]");
	i = 1;
	while (i < argc)
	{
		if (checkfile(argv[i]) == 8)
		{
			ft_putstr(argv[i]);
			ft_putendl(" is invalid.");
		}
		check = check + checkfile(argv[i]);
		i++;
	}
	if (check <= 14 && check != 8)
		pick_fract(check);
	return (0);
}
