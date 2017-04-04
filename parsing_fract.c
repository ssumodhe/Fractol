/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_fract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:06:15 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/04/04 16:49:03 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		pick_fract(int check)
{
	if (check == 1 || check == 3 || check == 5 || check == 7)
	{
		printf("to do : julia\n");
	//	ft_julia();
	}
	if (check == 2 || check == 3 || check == 6 || check == 7)
	{
		printf("to do : mandelbrot\n");
		ft_mandelbrot();
	}
	if (check == 4 || check == 5 || check == 6 || check == 7)
	{
		printf("to do : kitty\n");
	//	ft_kitty();
	}
	if (check > 7)
		return (1);
	return (0);
}

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
