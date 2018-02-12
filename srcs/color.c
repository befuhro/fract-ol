/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_color.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/11 18:09:31 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 06:18:46 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fract-ol.h"

void	first_color(char *image_string, float count, float x, float y)
{
	t_color color;
	float z;

	color.red = 0;
	color.green = 0;
	color.blue = 255;
	z = count * (255 / 15);
	color.green += z * count;
	color.red += (z * count) / 3;
	if (count == 15)
	{
		color.red = 255;
		color.green = 255;
		color.green = 255;
	}
	fill_pixel(image_string, x, y, color);
}

void	second_color(char *image_string, float count, float x, float y)
{
	t_color color;
	float z;

	color.red = 235;
	color.green = 30;
	color.blue = 30;
	z = count * (255 / 15);

	if (count == 1)
		count = 6;
	if ((int)count % 3 == 0 && count != 15)
		color.red -= (z * count);
	else if ((int)count % 2 == 0)
		color.blue += (z * count);
	if (count == 2)
	{
		color.green = 50;
		color.blue = 0;

	}
	if (count == 15)
	{
		color.red = 0;
		color.green = 0;
		color.blue = 0;
	}
	fill_pixel(image_string, x, y, color);
}

void	third_color(char *image_string, float count, float x, float y)
{
	t_color color;
	float z;

	color.red = 0;
	color.green = 0;
	color.blue = 255;
	z = count * (255 / 15);
	if (count == 15)
	{
		color.red = 0;
		color.green = 0;
		color.blue = 0;
	}
	fill_pixel(image_string, x, y, color);
}
