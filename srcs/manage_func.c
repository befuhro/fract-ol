/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   manage_func.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 04:42:33 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 16:10:32 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

t_ptrcolor	*initcolor(void)
{
	t_ptrcolor	*ptr;

	ptr = (t_ptrcolor*)malloc(sizeof(t_ptrcolor) * 3);
	ptr[0] = &eclipse;
	ptr[1] = &strange;
	ptr[2] = &royal;
	return (ptr);
}

t_ptrfract	*initfract(void)
{
	t_ptrfract	*ptr;

	ptr = (t_ptrfract*)malloc(sizeof(t_ptrfract) * 3);
	ptr[0] = &manage_mandelbrot;
	ptr[1] = &manage_julia;
	ptr[2] = &manage_burningship;
	return (ptr);
}
