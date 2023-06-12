/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_point_coord.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:11:37 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/16 04:21:57 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	set_point_offset_and_zoom(t_point *point, t_fdf *fdf)
{
	point->x += fdf->offset.x;
	point->y += fdf->offset.y;
	point->z += fdf->offset.z;
	point->x *= fdf->offset.zoom;
	point->y *= fdf->offset.zoom;
	point->z *= fdf->offset.zoom;
}

static t_point	set_point(t_fdf *fdf, t_coord coord)
{
	t_point	point;

	coord.x *= fdf->map.x_gap;
	coord.y *= fdf->map.y_gap;
	coord.z *= fdf->map.z_gap * fdf->z_ratio;
	if (fdf->projection_flag == 1)
	{
		point.x = (coord.x - coord.y) * cos(M_PI / 6);
		point.y = (coord.x + coord.y) * sin(M_PI / 6) - coord.z;
	}
	else if (fdf->projection_flag == 0)
	{
		point.x = coord.x;
		point.y = coord.y;
	}
	point.z = coord.z;
	point.color = 0x00FFFFFF;
	set_point_offset_and_zoom(&point, fdf);
	x_rotation(&point, fdf->angle.alpha);
	y_rotation(&point, fdf->angle.beta);
	z_rotation(&point, fdf->angle.gamma);
	point.x += (WIN_WIDTH / 2);
	point.y += (WIN_HEIGHT / 2);
	return (point);
}

static void	set_point_line(t_fdf *fdf, t_point *point_line, int y)
{
	int	x;

	x = 0;
	while (x < fdf->map.width)
	{
		point_line[x] = set_point(fdf, fdf->coords[y][x]);
		x++;
	}
}

t_point	**set_point_coord(t_fdf *fdf)
{
	t_point	**points;
	t_point	*point_line;
	int		y;

	points = malloc(sizeof(t_point) * fdf->map.height);
	if (!points)
		print_error("malloc error\n");
	y = 0;
	while (y < fdf->map.height)
	{
		point_line = malloc(sizeof(t_point) * fdf->map.width);
		if (!point_line)
			print_error("malloc error\n");
		set_point_line(fdf, point_line, y);
		points[y] = point_line;
		y++;
	}
	return (points);
}
