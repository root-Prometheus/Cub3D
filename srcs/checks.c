/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbattal <rbattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:09:03 by cbolat            #+#    #+#             */
/*   Updated: 2023/10/28 15:45:51 by rbattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
/*
.'dan sonraki uzantıları kontrol ediyor
*/

int	ft_extention_check(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 4)
		return (0);
	if (ft_strcmp(str + len - 4, ".cub") != 0)
		return (0);
	return (1);
}

int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
