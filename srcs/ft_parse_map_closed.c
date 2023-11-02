/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_closed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbattal <rbattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:38:51 by cbolat            #+#    #+#             */
/*   Updated: 2023/10/28 16:25:28 by rbattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
/*
i = satır sayısı, j = sütun sayısı
ilk sağ, sol, alt ve üstteki boşlukları kontrol eder "0NSEW" ile 
	çevrili olup olmadığını kontrol eder. varsa hata verir, 1 döndürür
*/

static int	ft_is_component_sur(char **map, int i, int j)
{
	if ((map[i][j + 1] && ft_strchr("0NSEW", map[i][j + 1]))
		|| (j - 1 > 0 && map[i][j - 1] && ft_strchr("0NSEW", map[i][j - 1]))
		|| (map[i + 1] && map[i + 1][j] && ft_strchr("0NSEW", map[i + 1][j]))
		|| (i - 1 > 0 && map[i - 1] && map[i - 1][j]
			&& ft_strchr("0NSEW", map[i - 1][j])))
		return (1);
	return (0);
}
/*
ilk olarak pozisyonun sağında, solunda, altında ve üstünde 
	boşluk olup olmadığını kontrol eder
boşluk içermediği ve sınrlarda olmadığı sürece hata (1) döndürür
*/

static int	ft_space_surr_check(char **map, int i, int j)
{
	if (!map[i][j + 1]
		|| (map[i][j + 1]
			&& map[i][j + 1] == ' '))
		return (1);
	else if (j - 1 < 0
		|| (j - 1 >= 0
			&& map[i][j - 1] == ' '))
		return (1);
	else if (!map[i + 1]
		|| (map[i + 1]
			&& j >= (int)ft_strlen(map[i + 1]))
		|| (map[i + 1]
			&& j < (int)ft_strlen(map[i + 1])
			&& map[i + 1][j] == ' '))
		return (1);
	else if (i - 1 < 0
		|| (i - 1 >= 0
			&& j >= (int)ft_strlen(map[i - 1]))
		|| (i - 1 >= 0
			&& j < (int)ft_strlen(map[i - 1])
			&& map[i - 1][j] == ' '))
		return (1);
	return (0);
}
/*
mapin geçerli olup olmadığını kontrol eder
eğer geçersiz veya eksik mapse 0 döndürür
*/

static int	ft_surrounding_check(char **map, int i, int j)
{
	if (map[i][j] == ' ' && ft_is_component_sur(map, i, j))
		return (printf("Error. Invalid map: misplaced space ' ' \n"), 0);
	else if (ft_strchr("0NSEW", map[i][j]))
	{
		if (ft_space_surr_check(map, i, j) == 1)
		{
			if (map[i][j] == EMPTY_SPACE)
				printf("Error. Invalid map: misplaced space '0'\n");
			else
				printf("Error. Invalid map: misplaced component\n");
			return (0);
		}
	}
	return (1);
}
/*
mapin kapalı olup olmadığını kontrol eder
*/

int	ft_check_map_closed(t_map *map)
{
	int	index[2];

	ft_fill_garbage(index, 2);
	while (map->map[index[0]])
	{
		index[1] = 0;
		while (map->map[index[0]][index[1]])
		{
			if (ft_strchr(" 0NWSE", map->map[index[0]][index[1]]))
			{
				if (ft_surrounding_check(map->map, index[0], index[1]) == 0)
					return (0);
			}
			index[1]++;
		}
		index[0]++;
	}
	return (1);
}
