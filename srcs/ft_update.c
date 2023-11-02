/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbattal <rbattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:13:14 by cbolat            #+#    #+#             */
/*   Updated: 2023/10/31 14:12:12 by rbattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_update(t_data *data)
{
	ft_move_player(data);//burası ve
	ft_render(data, 0.0);//burası öenmli geri kalanlar stabil kontrol ve şartlar
	mlx_clear_window(data->mlx.display_connector, data->mlx.win);
	mlx_put_image_to_window(data->mlx.display_connector,
		data->mlx.win, data->mlx.img.img, 0, 0);
	return (0);
}
