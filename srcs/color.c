/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_color.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/11 18:09:31 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/21 23:43:50 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fract-ol.h"

void	first_color(char *image_string, double count, double x, double y)
{
	t_color color;
	//	double z;

	(void)count;
	color.blue = (255 / 80) * 5;
	color.green = 0;
	color.red = (count * (255 / 80) / 1.5);

	if (count - 5 > 0)
	{
		color.blue+= (count - 5) * (255 / 80);
	
	
	}
	if (count == 101)
	{
		color.blue = 0;
		color.green = 0;
		color.red = 0;
	}


	fill_pixel(image_string, x, y, color);
}

void	second_color(char *image_string, double count, double x, double y)
{
	t_color color;
	double z;

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
		color.green = 200;
	if (count == 101)
	{
		color.red = 0;
		color.green = 0;
		color.blue = 0;
	}
	fill_pixel(image_string, x, y, color);
}

void	third_color(char *image_string, double count, double x, double y)
{
	t_color color;
	double z;

	color.red = 0;
	color.green = 225;
	color.blue = 30;
	z = count * (255 / 100);
	color.blue += (z * count) * 2;
	color.red += (z * count);
	if (count == 101)
	{
		color.red = 0;
		color.green = 0;
		color.blue = 0;
	}
	fill_pixel(image_string, x, y, color);
}
