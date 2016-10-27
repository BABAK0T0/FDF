/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_put.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 03:50:09 by nrandria          #+#    #+#             */
/*   Updated: 2016/04/13 15:53:42 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point			calcul(t_point *p, t_info *i)
{
	t_point		pnew;

	pnew.x =
		i->xstart + ((sqrt(2.0) / 2.0) * ((p->x * i->zoom) - (p->y * i->zoom)));
	pnew.y =
		i->ystart - ((sqrt(2.0 / 3.0) * (p->z * i->zoom / i->deep)) -
				((1 / sqrt(6)) * (i->zoom * (p->x + p->y))));
	return (pnew);
}

void			put_img(t_info *i)
{
	i->img = mlx_new_image(i->mlx, WIDTH, HEIGTH);
	i->ptr_img =
		mlx_get_data_addr(i->img, &(i->bpp), &(i->img_line), &(i->endian));
	put_map(i);
	mlx_put_image_to_window(i->mlx, i->win, i->img, 0, 0);
	mlx_destroy_image(i->mlx, i->img);
}

void			put_map(t_info *i)
{
	t_list		*tmp;

	tmp = i->list;
	while (tmp->next)
	{
		if ((((t_point *)tmp->content)->nb % i->line_size) != 0)
			put_line(calcul(tmp->content, i), calcul(tmp->next->content, i), i);
		if (!(((t_point *)tmp->content)->nb >
					(i->line_size * (i->nb_line - 1))))
			put_line(calcul(tmp->content, i), calcul(get_lst_nb(tmp, i), i), i);
		tmp = tmp->next;
	}
}

void			put_line(t_point p1, t_point p2, t_info *i)
{
	t_algo		algo;

	algo.dx = ft_abs((p2.x - p1.x));
	algo.sx = p1.x < p2.x ? 1 : -1;
	algo.dy = ft_abs((p2.y - p1.y));
	algo.sy = p1.y < p2.y ? 1 : -1;
	algo.err = (algo.dx > algo.dy ? algo.dx : -algo.dy) / 2;
	while (!(p1.x == p2.x && p1.y == p2.y))
	{
		put_pixel(p1.x, p1.y, i);
		algo.e2 = algo.err;
		if (algo.e2 > -algo.dx)
		{
			algo.err -= algo.dy;
			p1.x += algo.sx;
		}
		if (algo.e2 < algo.dy)
		{
			algo.err += algo.dx;
			p1.y += algo.sy;
		}
	}
}

void			put_pixel(int x, int y, t_info *i)
{
	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGTH)
	{
		i->ptr_img[(i->img_line * y) + (4 * x) + 2] = i->color_b;
		i->ptr_img[(i->img_line * y) + (4 * x) + 1] = i->color_g;
		i->ptr_img[(i->img_line * y) + (4 * x)] = i->color_r;
	}
}
