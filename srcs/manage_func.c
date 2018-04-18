/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   manage_func.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 04:42:33 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/18 15:00:26 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fract-ol.h"

ptrcolor	*initcolor(void)
{
	ptrcolor 	*ptr;

	ptr = (ptrcolor*)malloc(sizeof(ptrcolor) * 3);
	ptr[0] = &eclipse;
	ptr[1] = &strange;
	ptr[2] = &royal;
	return (ptr);
}

ptrfract	*initfract(void)
{
	ptrfract	*ptr;

	ptr = (ptrfract*)malloc(sizeof(ptrfract) * 3);
	ptr[0] = &manage_mandelbrot;
	ptr[1] = &manage_julia;
	ptr[2] = &manage_burningship;
	return (ptr);
}
