/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 12:55:10 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 21:51:15 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include <fcntl.h>
# include "mlx.h"
# include <stdlib.h>
# include "libft.h"
# include <math.h>

typedef struct	s_coord
{
	float x;
	float y;
}				t_coord;

typedef struct	s_whole
{
	void	*init;
	void	*win;
}				t_whole;

void		cercle(t_whole *whole, int x, int y, int r);

#endif
