/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:47:16 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/04/04 16:30:54 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	int		i;
	int		check;

	if (argc != 4 && argc != 3 && argc != 2)
	{
		ft_putendl("usage: ./fractol [mandelbrot | julia | kitty]");
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		check = check + checkfile(argv[i]);
		i++;
	}
	if (pick_fract(check) == 1)
	{
		ft_putendl("usage: ./fractol [mandelbrot | julia | kitty]");
		return (0);
	}
	return (0);
}
