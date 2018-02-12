/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_pixel.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/11 23:13:32 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 05:53:54 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fract-ol.h"

void	fill_pixel(char *image_string, int x, int y, t_color color)
{
	int	position;

	position = ((y * 1080) + x) * 4;
	image_string[position + 2] = color.red;
	image_string[position + 1] = color.green;
	image_string[position + 4] = color.blue;
}
