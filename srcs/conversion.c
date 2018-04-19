/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conversion.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/14 19:34:29 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 14:56:05 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	conv(int x, int y, t_comp *conv, t_fract f)
{
	conv->re = f.minx + (f.maxx - f.minx) / WIDTH * x;
	conv->im = f.miny + (f.maxy - f.miny) / HEIGHT * y;
}
