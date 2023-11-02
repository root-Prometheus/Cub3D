/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbattal <rbattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:03:30 by cbolat            #+#    #+#             */
/*   Updated: 2023/10/26 14:23:13 by rbattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	c;
	size_t	f;

	f = 0;
	c = start;
	if (s == 0)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	while (f < len && s[f + start] != '\0')
		f++;
	str = malloc((f + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < len && s[c] != '\0')
		str[i++] = s[c++];
	str[i] = '\0';
	return (str);
}
