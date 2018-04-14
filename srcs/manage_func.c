/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   manage_func.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 04:42:33 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/20 18:07:07 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fract-ol.h"

ptrcolor	*initcolor(void)
{
	ptrcolor 	*ptr;

	ptr = (ptrcolor*)malloc(sizeof(ptrcolor) * 3);
	ptr[0] = &violet;
	ptr[1] = &red;
	ptr[2] = &green;
	return (ptr);
}

ptrfract	*initfract(void)
{
	ptrfract	*ptr;

	ptr = (ptrfract*)malloc(sizeof(ptrfract) * 2);
	ptr[0] = &manage_mandelbrot;
	ptr[1] = &manage_julia;
	return (ptr);
}