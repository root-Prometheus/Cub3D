/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_import_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbattal <rbattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:12:12 by cbolat            #+#    #+#             */
/*   Updated: 2023/10/28 16:15:21 by rbattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
/*
map structını başlangıç değerleriyle doldurur
*/

static void	ft_init_map(t_map *map)
{
	map->north.img = NULL;
	map->south.img = NULL;
	map->west.img = NULL;
	map->east.img = NULL;
	map->ceiling_c = F_C_COLOR_DEF;
	map->floor_c = F_C_COLOR_DEF;
	map->map = NULL;
}
/*
oyuncu başlangıç pozisyonunu elinde olan harften bulur
ona göre oyuncunun açısını belirler
*/

static void	ft_get_player_ang(t_data *data, double x, double y)
{
	if (data->map.map[(int)y][(int)x] == 'N')
		data->player.angle = M_PI_2;
	else if (data->map.map[(int)y][(int)x] == 'S')
		data->player.angle = M_PI_2 * 3.0;
	else if (data->map.map[(int)y][(int)x] == 'W')
		data->player.angle = 0;
	else if (data->map.map[(int)y][(int)x] == 'E')
		data->player.angle = M_PI;
}

static void	ft_init_player_starting_pos(t_data *data)
{
	int	i[2];

	ft_fill_garbage(i, 2);
	while (data->map.map[i[0]])
	{
		i[1] = 0;
		while (data->map.map[i[0]][i[1]])
		{
			if (ft_strchr("NSEW", data->map.map[i[0]][i[1]]))
			{
				data->player.pos.x = (double)i[1] + OFF_SET;
				data->player.pos.y = (double)i[0] + OFF_SET;
				ft_get_player_ang(data, data->player.pos.x, data->player.pos.y);
				return ;
			}
			i[1]++;
		}
		i[0]++;
	}
}
/*
ft_import_map fonksiyonu harita kontrollerini yapar
bu sırada texture doldurur, mapi ayıklar, oyuncu başlangıç pozisyonunu belirler
eğer harita kontrolleri başarılıysa 1 döndürür
*/

int	ft_import_map(t_data *data, char *argv)
{
	int	fd;
	int	return_value;

	ft_init_map(&data->map);
	if (ft_extention_check(argv) == 0)
		return (printf("Error. Invalid file extension. ./cub3d <file.cub>\n"), 0);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (printf("Error. Couldn't open <%s> file.\n", argv), 0);
	return_value = ft_fill_textures(data, fd);
	if (return_value == 0)
		return (0);
	return_value = ft_parse_map(&data->map, fd);
	if (return_value == 0)
		return (0);
	ft_init_player_starting_pos(data);
	close(fd);
	return (1);
}
