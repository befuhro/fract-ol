/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   manage_func.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 04:42:33 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 14:58:01 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fract-ol.h"

ptr2func	*makeTab(void)
{
	ptr2func *ptrColor;

	ptrColor = (ptr2func*)malloc(sizeof(ptr2func) * 3);
	ptrColor[0] = &first_color;
	ptrColor[1] = &second_color;
	ptrColor[2] = &third_color;
	return (ptrColor);
}
