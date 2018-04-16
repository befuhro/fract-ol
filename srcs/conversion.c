/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conversion.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/14 19:34:29 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 20:59:33 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fract-ol.h"

void	conv(int x, int y, t_comp *conv, t_fract f)
{
	conv->re = f.minX + (f.maxX - f.minX) / WIDTH * x;
	conv->im = f.minY + (f.maxY - f.minY) / HEIGHT * y;
}
