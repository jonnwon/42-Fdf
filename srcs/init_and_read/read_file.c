/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 04:25:47 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/16 02:51:27 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	check_file(char *path)
{
	int	i;

	i = 0;
	while (path[i])
		i++;
	if (i < 5)
		print_error("file name error\n");
	if (path[i - 1] != 'f' || path[i - 2] != 'd' \
		|| path[i - 3] != 'f' || path[i - 4] != '.')
		print_error("file format error\n");
}

static void	init_gap(t_fdf *fdf)
{
	fdf->map.x_gap = (double)WIN_WIDTH / fdf->map.width / 2;
	fdf->map.y_gap = (double)WIN_HEIGHT / fdf->map.height / 2;
	while (fdf->map.x_gap < 1 || fdf->map.y_gap < 1)
	{
		if (fdf->map.x_gap < 1)
			fdf->map.x_gap += 0.1;
		if (fdf->map.y_gap < 1)
			fdf->map.y_gap += 0.1;
	}
	if (fdf->map.x_gap > fdf->map.y_gap)
		fdf->map.z_gap = (fdf->map.x_gap - fdf->map.y_gap) / 2;
	else if (fdf->map.x_gap < fdf->map.y_gap)
		fdf->map.z_gap = (fdf->map.y_gap - fdf->map.x_gap) / 2;
}

void	read_file(t_fdf *fdf, char *path)
{
	check_file(path);
	init_map_info(fdf, path);
	init_coords(fdf, path);
	init_gap(fdf);
}
