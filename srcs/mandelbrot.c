/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mandelbrot.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/11 18:10:50 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 00:59:45 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fract-ol.h"

 void    mandelbrot(t_fract *fract, char *image_string, ptr2func ptr)
{
	fract->y = -1;
	while (++fract->y < 700)
	{
		fract->x = -1;
		while (++fract->x < 1080)
		{
			fract->rC = fract->minX + (fract->maxX - fract->minX) / 1080 * fract->x;
			fract->iC = fract->minY + (fract->maxY - fract->minY) / 700 * fract->y;
			fract->rZ = 0;
			fract->iZ = 0;
			fract->count = 0;
			while (fract->count < 20 && 
				fract->rZ * fract->rZ + fract->iZ * fract->iZ <= 4)
			{
				fract->I = fract->iZ;
				fract->iZ = 2 * fract->rZ * fract->I + fract->iC;
				fract->rZ = fract->rZ * fract->rZ - fract->I * 
					fract->I + fract->rC;
				fract->count++;
				ptr(image_string, fract->count, fract->x, fract->y);
			}
		}
	}
}
