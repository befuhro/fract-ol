/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/11 18:10:20 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 15:40:42 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fract-ol.h"

void	init_mlx(t_all *all)
{
	int		bpp;
	int		s_l;
	int		endian;

	all->init = mlx_init();
	all->win = mlx_new_window(all->init, WIDTH, HEIGHT, "fract-ol");
	all->image_ptr = mlx_new_image(all->init, WIDTH, HEIGHT);
	all->image_string = mlx_get_data_addr(all->image_ptr, &bpp, &s_l, &endian); 
}

void	init_fract(t_all *all)
{
	all->indexColor = 0;
	all->fract = (t_fract*)malloc(sizeof(t_fract));
	all->fract->minX = -2;
    all->fract->maxX = 2;
    all->fract->minY = -1.25;
    all->fract->maxY = 1.25;
}

int	main(void)
{
	t_all	*all;

	all = (t_all*)malloc(sizeof(t_all));
	init_mlx(all);
	init_fract(all);
	all->ptrColor = makeTab();
	mlx_put_image_to_window(all->image_string, all->win, all->image_ptr, 0, 0);
	mlx_mouse_hook(all->win, mouse_func, all);
	mlx_key_hook(all->win, key_func, all);
	mlx_loop(all->init);
	return (0);
}
