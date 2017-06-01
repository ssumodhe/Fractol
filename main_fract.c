/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:47:16 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/06/01 19:52:01 by ssumodhe         ###   ########.fr       */
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
		num = 4;
	else if (ft_strcmp("douady", str) == 0)
		num = 13;
	else
		num = 40;
	return (num);
}

int		main(int argc, char **argv)
{
	int		i;
	int		cpt;
	int		check;

	if (argc != 4 && argc != 3 && argc != 2)
		ft_exit("usage: ./fractol [mandelbrot | julia | douady]");
	i = 1;
	cpt = 0;
	while (i < argc)
	{
		if (checkfile(argv[i]) == 40)
		{
			ft_putstr(argv[i]);
			ft_putendl(" is invalid.");
			cpt++;
		}
		check = check + checkfile(argv[i]);
		i++;
	}
	if (cpt >= 1)
		ft_exit("usage: ./fractol [mandelbrot | julia | douady]");
	if (check <= 93 && check != 40 && check != 80)
		pick_fract(check);
	return (0);
}
