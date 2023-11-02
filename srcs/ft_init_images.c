/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbattal <rbattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:05:31 by cbolat            #+#    #+#             */
/*   Updated: 2023/10/28 16:15:57 by rbattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
/*
mlx_new_image() creates a new image in memory.
mlx_get_data_addr() returns information about the created image.
*/

int	ft_init_images(t_data *data)
{
	data->mlx.img.img = mlx_new_image(data->mlx.display_connector,
			WIDTH, HEIGHT);
	if (!data->mlx.img.img)
		return (printf("Error\nCouldn't initilize window.\n"), 0);
	data->mlx.img.get_addr = (int *)mlx_get_data_addr(data->mlx.img.img,
			&data->mlx.img.bits_per_pixel, &data->mlx.img.line_length,
			&data->mlx.img.steps);
	return (1);
}
