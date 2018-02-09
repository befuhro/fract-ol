/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rely_point.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 16:31:23 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 22:18:59 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		ft_abs(int n)
{
	if (n < 0)
		return (-1);
	return (n);
}

int		ft_hex2(float *z)
{
	int hex2;

	hex2 = 0;
	while (*z >= 16 || *z <= -16)
	{
		if (*z >= 16)
		{
			*z -= 16;
			hex2++;
		}
		else
		{
			*z += 16;
			hex2--;
		}
	}
	return (hex2);
}

int		ft_hex1(float *z)
{
	int hex1;

	hex1 = 0;
	while (*z >= 1 || *z < 0)
	{
		if (*z > 0)
		{
			*z -= 1;
			hex1++;
		}
		else
		{
			*z += 1;
			hex1--;
		}
	}
	return (hex1);
}

void	print_color(void *init, void *win, float count, float x, float y)
{
	int color;
	int hex1;
	int hex2;
	float z;

	color = 0;
	count--;
	z = count * (255 / 15);
	hex2 = ft_hex2(&z);
	hex1 = ft_hex1(&z);
	color += (hex2 * pow(16, 3)) + (hex1 * pow(16, 2)) + (hex2 * 16) + hex1;
	mlx_pixel_put(init, win, x, y, color);
}
