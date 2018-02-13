/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fract-ol.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/11 18:08:11 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 20:25:17 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include <fcntl.h>
# include "mlx.h"
# include <stdlib.h>
# include "libft.h"
# include <math.h>

typedef	void	(*ptr2func)(char *, float, float, float);

typedef struct	s_color
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}				t_color;

typedef	struct	s_fract
{
	float	minX;
	float	maxX;
	float	minY;
	float	maxY;
	float	x;
	float	y;
	float	rC;
	float	iC;
	float	rZ;
	float	iZ;
	float	I;
	float	Z;
	int		count;
}			t_fract;

typedef struct	s_all
{
	void			*init;
	void			*win;
	void			*image_ptr;
	char			*image_string;
	ptr2func  		*ptrColor;
	int				indexColor;
	t_fract			*fract;
}				t_all;

void	mandelbrot(t_fract *fract, char *image_string, ptr2func ptr);
int		ft_hex1(float *z);
int		ft_hex2(float *z);
void    first_color(char *image_string, float count, float x, float y);
void    second_color(char *image_string, float count, float x, float y);
void    third_color(char *image_string, float count, float x, float y);
void	fill_pixel(char *image_string, int x, int y, t_color color);
int		mouse_func(int mousecode, int x, int y, t_all *all);
int		key_func(int keycode, t_all *all);
void	zoom(t_all *all, int x, int y);
void	unzoom(t_all *all, int x, int y);
ptr2func	*makeTab(void);

#endif
