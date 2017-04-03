/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:47:16 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/04/03 20:47:42 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
	{
		ft_putstr("usage: ./fractol source_file\n");
		return (0);
	}
	ft_checkfile(argv[1]);
	if ((fd = open(argv[1], O_RDWR)) < 0)
	{
		ft_putstr(RED"open: fail\n"RESET"Try another source file\n");
		return (0);
	}
	ft_prog(fd);
	if (close(fd) < 0)
	{
		ft_putstr(RED"close: fail\n"RESET);
		return (0);
	}
	return (0);
}
