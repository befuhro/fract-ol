/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 16:28:20 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 21:51:11 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fract'ol.h"

void	treatment(void)
{
	t_whole		*ptr;
	t_whole		whole;
	int			 r;

	r = 200;
	ptr = &whole;
	whole.init = mlx_init();
	whole.win = mlx_new_window(whole.init, 1080, 720, "mlx fdf");
	while (r > 0)
	{
		cercle(ptr, 540, 360, r);
		r--;
	}
	mlx_loop(ptr->init);
}

int		main(void)
{
	treatment();
	return (0);
}
