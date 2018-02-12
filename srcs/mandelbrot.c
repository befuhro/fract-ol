/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mandelbrot.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/11 18:10:50 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 04:31:46 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fract-ol.h"

 void    mandelbrot(char *image_string, ptr2func ptr)
{
	float   minX = -2.6;
	float   maxX = 2.6;
	float   minY = -1.5;
	float   maxY = 1.5;
	float   x = 0;
	float   y = 0;
	float   rC;
	float   iC;
	float   rZ;
	float   iZ;
	float   I;
	float   count;
	float   R;
	while (y < 700)
	{
		x = 0;
		while (x < 1080)
		{
			rC = minX + (maxX - minX) / 1080 * x;
			iC = minY + (maxY - minY) / 700 * y;
			rZ = 0;
			iZ = 0;
			count = 0;
			while (count < 15 && rZ * rZ + iZ * iZ <= 4)
			{
				R = rZ;
				I = iZ;
				rZ = R * R - I * I + rC;
				iZ = 2 * R * I + iC;
				count++;
				ptr(image_string, count, x, y);
			}
			x++;
		}
		y++;
	}
	(void)link;
}
