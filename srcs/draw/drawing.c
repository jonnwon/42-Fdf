/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:23:26 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/16 02:50:47 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	init_img_and_addr(t_fdf *fdf)
{
	fdf->img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!fdf->img)
		print_error("mlx_new_image func error\n");
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, \
						&fdf->line_length, &fdf->endian);
	if (!fdf->addr)
		print_error("mlx_get_data_addr func error\n");
}

void	drawing(t_fdf *fdf)
{
	t_point	**points;
	int		x;
	int		y;

	init_img_and_addr(fdf);
	points = set_point_coord(fdf);
	y = 0;
	while (y < fdf->map.height)
	{
		x = 0;
		while (x < fdf->map.width)
		{
			if (x < fdf->map.width - 1)
				draw_line(points[y][x], points[y][x + 1], fdf);
			if (y < fdf->map.height - 1)
				draw_line(points[y][x], points[y + 1][x], fdf);
			x++;
		}
		free(points[y]);
		y++;
	}
	free(points);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
