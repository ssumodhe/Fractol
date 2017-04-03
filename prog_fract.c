/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 14:51:21 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/04/03 20:47:46 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_exit(char *str)
{
	ft_putendl(str);
	exit(1);
}

void	ft_prog(int fd)
{
	(void)fd;
//	t_data	*data;
//	t_map	*map;
	create_window();
//	data = ft_getmap(fd);
//	map = ft_parsemap(data);
//	data->map = map;
//	ft_graph_part(map, data);
}
