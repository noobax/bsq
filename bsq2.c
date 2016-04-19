/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noobax <nerdz78@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 21:55:22 by noobax            #+#    #+#             */
/*   Updated: 2016/04/19 17:43:52 by noobax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (str[0] == '-')
		i = 1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	if (str[0] == '-')
		res *= -1;
	return(res);
}

void	ft_print_map(char **str, int i, int j, int size)
{
	int	x;
	int	y;

	y = 0;
	while(*str[y])
	{
		x = 0;
		while (str[y][x])
		{
			if (y >= j && y <= (j + size - 1) 
				&& x >= i && x <= (i + size - 1))
				ft_putchar('x');
			else
				ft_putchar(str[y][x]);
			x++;
		}
		y++;
	}
}
