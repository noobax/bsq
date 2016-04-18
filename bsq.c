/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noobax <nerdz78@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 22:45:29 by noobax            #+#    #+#             */
/*   Updated: 2016/04/18 13:23:47 by noobax           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#define BUF_SIZE 4096

int	ft_square_maker(char **str, int end, int i, int j)
{
	int	size;
	int	x;
	int	y;
	
	end -= 1;
	size = 0;
	x = i;
	y = j;
	while (str[y][x] != 'o' && y < end && str[y][x] != '\n')
	{
		x = i + size;
		y = j;
		while (x != i && str[y][x] != 'o' && str[y][x] != '\n' 
			&& y != end)
		{
			if (y < j + size)
				y++;
			else
				x--;
		}
		if (str[y][x] != 'o' && str[y][x] != '\n')
			size++;
	}
	return(size);
}

void	ft_scanner(char **map, int x, int y)
{
	int	i;
	int	j;
	int	size;
	int	end;

	size = 0;
	end = y;
	y = 0;
	while (y < end)
	{
		x = 0;
		while (map[y][x] != '\n')
		{
			if (size < ft_square_maker(map, end, x, y))
			{
				size = ft_square_maker(map, end, x, y);
				i = x;
				j = y;
			}
			x++;
		}
		y++;
	}
	ft_print_map(map, i, j, size, end);
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
	map = (char**)malloc(sizeof(map) * y);
	while (i < y)
	{
		map[i] = (char*)malloc(sizeof(*map) * x);
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
