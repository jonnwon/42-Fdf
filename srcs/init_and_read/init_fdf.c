/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 04:21:45 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/16 02:51:13 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	init_angle(t_fdf *fdf)
{
	fdf->angle.alpha = 0;
	fdf->angle.beta = 0;
	fdf->angle.gamma = 0;
}

void	init_offset(t_fdf *fdf)
{
	fdf->offset.x = 0;
	fdf->offset.y = 0;
	fdf->offset.z = 0;
	fdf->offset.zoom = 1;
}

void	init_fdf(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		print_error("mlx error\n");
	fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	if (!fdf->win)
		print_error("win error\n");
	fdf->coords = NULL;
	init_angle(fdf);
	init_offset(fdf);
	fdf->projection_flag = 1;
	fdf->z_ratio = 1;
}
