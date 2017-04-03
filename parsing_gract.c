/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_gract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 19:42:26 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/04/03 20:47:40 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		checkfile(char *str)
{
	int		num;

	num = 0;
	if (ft_strcmp("julia", str) == 0)
		num = 1;
	if (ft_strcmp("mandelbrot", str) == 0)
		num = num + 2;
	if (ft_strcmp("kitty", str) == 0)
		num = num + 3;
	else
		num = 0;
	return (num);
}
