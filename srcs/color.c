/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_color.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/11 18:09:31 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 19:20:43 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fract-ol.h"

void	violet(char *image_string, double count, double x, double y)
{
	t_color	color;
	double	z;

	z = 255 / ITMAX;
	color.green = 0;
	color.red = 0;
	color.blue = z * count;
	fill_pixel(image_string, x, y, color);
}

void	red(char *image_string, double count, double x, double y)
{
	t_color color;
	double z;

	z = 255 / ITMAX;
	color.red = z * count;
	color.green = 0;
	color.blue = 0;
	fill_pixel(image_string, x, y, color);
}

void	green(char *image_string, double count, double x, double y)
{
	t_color color;
	double z;

	z = 255 / ITMAX;
	color.red = 0;
	color.green = z * count;
	color.blue = 0;
	fill_pixel(image_string, x, y, color);
}
