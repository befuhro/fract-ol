/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_color.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/11 18:09:31 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/16 18:09:08 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fract-ol.h"

void	eclipse(char *image_string, double count, double x, double y)
{
	t_color	color;

	if (count < 35)
	{
		color.red = 153 + ((float)99 / 35) * count;
		color.green = 204 - ((float)37 / 35) * count;
		color.blue = 255 - ((float)198 / 35) * count;
	}
	else
	{
		color.red = 252 - ((float)62 / 65) * (count - 35);
		color.green = 167 - ((float)108 / 65) * (count - 35);
		color.blue = 57 + ((float)27 / 65) * (count - 35);
	}
	fill_pixel(image_string, x, y, color);
}

void	strange(char *image_string, double count, double x, double y)
{
	t_color	color;

	if (count < 25)
	{
		color.red = 191 - ((float)179 / 25) * count;
		color.green = 0 + ((float)89 / 25) * count;
		color.blue = 98 + ((float)21 / 25) * count;
	}
	else
	{
		color.red = 12 + ((float)59 / 75) * (count - 25);
		color.green = 89 + ((float)67 / 75) * (count - 25);
		color.blue = 119 - ((float)60 / 75) * (count - 25);
	}
	fill_pixel(image_string, x, y, color);
}

void	royal(char *image_string, double count, double x, double y)
{
	t_color	color;

	if (count < 25)
	{
		color.red = ((float)255 / 25) * count;
		color.green = ((float)255 / 25) * count;
		color.blue = 150 + ((float)105 / 25) * count;
	}
	else
	{
		color.red = 255;
		color.green = 255 - ((float)61 / 75) * (count - 25);
		color.blue = 255 - ((float)255 / 75) * (count - 25);
	}
	fill_pixel(image_string, x, y, color);
}
