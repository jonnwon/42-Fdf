/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 23:43:54 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/16 04:42:05 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static t_coord	*init_coord(t_fdf *fdf, int y, char **z_values)
{
	t_coord	*coord;
	int		i;
	int		z;

	coord = malloc(sizeof(t_coord) * fdf->map.width);
	if (!coord)
		print_error("malloc error\n");
	i = 0;
	while (i < fdf->map.width)
	{
		z = ft_atoi(z_values[i]);
		coord[i].x = i - fdf->map.x_origin;
		coord[i].y = y - fdf->map.y_origin;
		coord[i].z = z;
		i++;
	}
	return (coord);
}

static void	init_coord_line(t_fdf *fdf, char *line, int y)
{
	char	**z_values;
	int		i;

	z_values = ft_split(line, ' ');
	fdf->coords[y] = init_coord(fdf, y, z_values);
	i = 0;
	while (i < fdf->map.width)
	{
		free(z_values[i]);
		i++;
	}
	free(z_values);
}

void	init_coords(t_fdf *fdf, char *path)
{
	int		fd;
	int		y;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_error("file open error\n");
	fdf->coords = malloc(sizeof(t_coord *) * fdf->map.height);
	if (!fdf->coords)
		return ;
	y = 0;
	while (y < fdf->map.height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		init_coord_line(fdf, line, y);
		free(line);
		y++;
	}
	close(fd);
}
