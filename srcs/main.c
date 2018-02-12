/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/11 18:10:20 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 04:41:52 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fract-ol.h"

int	main(void)
{
	t_all	*all;
	int		bpp;
	int		s_l;
	int		endian;

	all = (t_all*)malloc(sizeof(t_all));
	all->init = mlx_init();
	all->win = mlx_new_window(all->init, 1080, 700, "fract-ol");
	all->ptrColor = makeTab();
	all->indexColor = 0;
	all->image_ptr = mlx_new_image(all->init, 1080, 700);
	all->image_string = mlx_get_data_addr(all->image_ptr, &bpp, &s_l, &endian); 
	mandelbrot(all->image_string, all->ptrColor[0]);
	mlx_put_image_to_window(all->image_string, all->win, all->image_ptr, 0, 0);
	mlx_key_hook(all->win, mouse_func, all);
	mlx_loop(all->init);
	return (0);
}
