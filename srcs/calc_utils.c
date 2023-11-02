/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbattal <rbattal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 01:01:27 by cbolat            #+#    #+#             */
/*   Updated: 2023/10/31 13:19:54 by rbattal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
/*
iki koordinat noktası (p1 ve p2) arasındaki mesafeyi hesaplamak için kullanılır.
nesnelerin, oyuncuların veya diğer varlıkların 
	birbirine olan uzaklığını belirler
İki nokta arasındaki x ve y koordinat farkları hesaplanır ve bu farkların kareleri alınır. 
Bu, x ve y eksenleri üzerindeki uzaklığın karelerini hesaplar.
X ve Y koordinat farklarının kareleri toplanır, bu da iki 
	nokta arasındaki toplam uzaklığın karesini verir.
son olarak uzaklığın kökü hesaplanır ve iki nokta arasındaki gerçek uzaklık hesaplanır.
iki nokta arasındaki Euclidean (Öklidyen) uzaklığı hesaplayan bir matematiksel işleme sahiptir.(dda)
*/

double	ft_distance(t_coordinates p1, t_coordinates p2)
{
	t_coordinates	distance;

	distance.x = powf(p2.x - p1.x, 2);
	distance.y = powf(p2.y - p1.y, 2);
	return (sqrtf(distance.x + distance.y));
}
/*
transparency (saydamlık), r (kırmızı), g (yeşil) ve b (mavi) değerleri 
	sırasıyla 0xFF, 0x80, 0x66, ve 0x33 olarak ayarlandığında, 
	fonksiyon aşağıdaki gibi bir renk kodunu oluşturur:
*/

int	ft_create_color(int transpancy, int r, int g, int b)
{
	return (transpancy << 24 | r << 16 | g << 8 | b);
}
/*
by increasing an angle and making it cyclic, 
ensuring that the angle stays within a certain boundary
*/

double	ft_update_radian(double radian, double inc)
{
	radian += inc;
	if (radian > 2 * M_PI)
		radian -= 2 * M_PI;
	else if (radian < 0)
		radian += 2 * M_PI;
	return (radian);
}
/*
dereceden radyana çevirme işlemi için kullanılır
bu fonksiyon Matematiksel Konsistens, hız-performans ve duyarlılık
	açısından daha iyi bir seçenek oluşturur.
*/

double	ft_deg_to_rad(double degree)
{
	return ((degree * M_PI) / 180.0);
}
