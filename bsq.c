/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noobax <nerdz78@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 22:45:29 by noobax            #+#    #+#             */
/*   Updated: 2016/04/19 18:32:45 by noobax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#define BUF_SIZE 4096

int	ft_square_maker(char **str, int i, int j)
{
	int	x;
	int	y;
	int	size;
	
	x = i;
	y = j;
	size = 0;
	while (*str[y + 1] && str[y][x + 2] && str[y][x] != 'o')
	{
		x = i + size;
		y = j;
		while (x != i && *str[y + 1] && 
			str[y][x + 2] && str[y][x] != 'o')
		{
			if (y < (j + size))
				y++;
			else
				x--;
		}
		if (str[y][x] != 'o')
			size++;
	}
	return(size);
}

void	ft_scanner(char **map, int x, int y)
{
	int	i;
	int	j;
	int	size;
	int	stock;

	stock = 0;
	size = 0;
	y = 0;
	while (*map[y])
	{
		x = 0;
		while (map[y][x])
		{
			stock = ft_square_maker(map, x, y);
			if (size < stock)
			{
				size = stock;
				i = x;
				j = y;
			}
			x++;
		}
		y++;
	}
	ft_print_map(map, i, j, size);
}

char	**ft_set_map(char *src, char **cpy)
{
	char	buf[2];
	int	x;
	int	y;
	
	while (*src++ != '\n')
	y = 0;
	x = 0;
	while (*src)
	{
		buf[0] = *src++;
		buf[1] = '\0';
		cpy[y][x] = buf[0];
		x++;
		if (buf[0] == '\n')
			y++;
		if (buf[0] == '\n')
			x = 0;
	}
	return(cpy);
}

void	bsq(char *str, int x, int y)
{
	char	**map;
	int	i;

	i = 0;
	map = (char**)malloc(sizeof(char*) * (y + 1));
	while (i < (y + 1))
	{
		map[i] = (char*)malloc(sizeof(char) * (x + 1));
		i++;
	}
	map = ft_set_map(str, map);
	ft_scanner(map, x, y);
}

int	main(void)
{
	int	ret;
	char	buf[BUF_SIZE + 1];
	int	x;
	int	y;

	while ((ret = read(0, buf, BUF_SIZE)))
		buf[ret] = '\0';
	x = 0;
	y = 0;
	while (buf[y] != '\n')
		y++;
	while (buf[y + x + 1] != '\n')
		x++;
	y = ft_atoi(buf);
	bsq(buf, x, y);
	return(0);
}
