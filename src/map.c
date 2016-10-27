/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 03:38:23 by nrandria          #+#    #+#             */
/*   Updated: 2016/04/26 15:32:21 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_error(char *file)
{
	if (!(ft_strcmp("/dev/random/", file)))
	{
		ft_putstr_fd("Undefined behavior.\n", 2);
		exit(-1);
	}
	else
	{
		ft_putstr_fd("No file ", 2);
		ft_putstr(file);
		ft_putstr_fd(" or no data found.\n", 2);
		exit(-1);
	}
}

void			add_pixel(int x, int y, int z, t_info *i)
{
	t_point		*p;
	static int	nb = 1;

	if (!(p = (t_point *)malloc(sizeof(t_point))))
		exit(2);
	p->x = x;
	p->y = y;
	p->z = z;
	p->nb = nb;
	nb++;
	ft_push_back(&(i->list), p, 0);
}

void			check_length(int x, int y, t_info *i)
{
	if (y == 0)
		i->line_size = x;
	else if (y != 0 && x != i->line_size)
	{
		ERROR;
	}
}

void			check_file(char *file)
{
	int			fd;
	char		*buf;

	fd = open(file, O_RDWR);
	buf = (char *)malloc(sizeof(char) * 2);
	if (!(read(fd, buf, 1)))
	{
		ft_putstr_fd("No data found.\n", 2);
		free(buf);
		exit(-1);
	}
	close(fd);
}

void			get_coord(char *file, t_info *i)
{
	int			fd;
	int			y;
	int			x;
	char		*line;
	char		**tmp;

	y = 0;
	check_file(file);
	fd = open(file, O_RDWR);
	(fd == -1) ? ft_error(file) : 0;
	while (get_next_line(fd, &line) > 0)
	{
		x = 0;
		tmp = ft_strsplit(line, ' ');
		while (tmp[x])
		{
			add_pixel(x, y, ft_atoi(tmp[x]), i);
			x++;
		}
		free_tab_line(tmp, line);
		check_length(x, y, i);
		y++;
	}
	i->nb_line = y;
	close(fd);
}
