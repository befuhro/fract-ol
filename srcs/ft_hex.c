/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_hex.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/11 18:05:41 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 00:05:39 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fract-ol.h"

int     ft_hex1(float *n)
{
	int hex1;

	hex1 = 0;
	while (*n >= 1 || *n < 0)
	{
		if (*n > 0)
		{
			*n -= 1;
			hex1++;
		}
		else
		{
			*n += 1;
			hex1--;
		}
	}
	return (hex1);
}

int     ft_hex2(float *n)
{
	int hex2;

	hex2 = 0;
	while (*n >= 16 || *n <= -16)
	{
		if (*n >= 16)
		{
			*n -= 16;
			hex2++;
		}
		else
		{
			*n += 16;
			hex2--;
		}
	}
	return (hex2);
}
