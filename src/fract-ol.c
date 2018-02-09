#include "fdf.h"
#include <stdio.h>

void	print_color(void *init, void *win, float count, float x, float y);



void	fractol(void *init, void *win)
{
	float	minX = -4;
	float	maxX = 4;
	float 	minY = -2.5;
	float 	maxY = 2.5;
	float	x = 0;
	float 	y = 0;
	float	rC;
	float	iC;
	float 	rZ;
	float	iZ;
	float	I;
	float	count;
	float 	R;
	while (y < 700)
	{
		x = 0;
		while (x < 1080)
		{
			rC = minX + (maxX - minX) / 1080 * x;
			iC = minY + (maxY - minY) / 700 * y;
			rZ = 0;
			iZ = 0;
			count = 0;
			while (count < 15 && rZ * rZ + iZ * iZ <= 4)
			{
				R = rZ;
				I = iZ;
				rZ = R * R - I * I + rC;
				iZ = 2 * R * I + iC;
				count++;
				print_color(init, win, count, x, y);
			}
			x++;
		}
		y++;
	}
}

int	main(void)
{
	void	*init;
	void	*win;


	init = mlx_init();
	win = mlx_new_window(init, 1080, 700, "fract-ol");
	fractol(init, win);
	mlx_loop(init);
	return (0);
}
