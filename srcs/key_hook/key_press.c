/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:17:58 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/16 05:11:41 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	rotation_or_move_key(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_W)
		fdf->angle.alpha += M_PI / 180 * 3;
	else if (keycode == KEY_S)
		fdf->angle.alpha += (-1) * M_PI / 180 * 3;
	else if (keycode == KEY_A)
		fdf->angle.beta += (-1) * M_PI / 180 * 3;
	else if (keycode == KEY_D)
		fdf->angle.beta += M_PI / 180 * 3;
	else if (keycode == KEY_Q)
		fdf->angle.gamma += M_PI / 180 * 3;
	else if (keycode == KEY_E)
		fdf->angle.gamma += (-1) * M_PI / 180 * 3;
	else if (keycode == KEY_DOWN)
		fdf->offset.y -= 5;
	else if (keycode == KEY_UP)
		fdf->offset.y += 5;
	else if (keycode == KEY_RIGHT)
		fdf->offset.x -= 5;
	else if (keycode == KEY_LEFT)
		fdf->offset.x += 5;
}

static void	zoom_or_projection_key(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_PLUS)
		fdf->offset.zoom += 0.1;
	else if (keycode == KEY_MINUS)
	{
		if (fdf->offset.zoom > 0.2)
			fdf->offset.zoom -= 0.1;
	}
	else if (keycode == KEY_O || keycode == KEY_I)
	{
		init_angle(fdf);
		if (keycode == KEY_O)
			fdf->projection_flag = 0;
		else if (keycode == KEY_I)
			fdf->projection_flag = 1;
	}
}

static void	reset_key(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_R)
	{
		init_offset(fdf);
		init_angle(fdf);
		fdf->z_ratio = 1;
		fdf->projection_flag = 1;
	}
}

static void	z_ratio_key(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_Z)
		fdf->z_ratio += 1;
	else if (keycode == KEY_X)
		fdf->z_ratio -= 1;
}

int	key_press(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(0);
	}
	if (keycode == KEY_W || keycode == KEY_S || \
		keycode == KEY_A || keycode == KEY_D || \
		keycode == KEY_Q || keycode == KEY_E)
		rotation_or_move_key(keycode, fdf);
	else if (keycode == KEY_UP || keycode == KEY_DOWN || \
			keycode == KEY_LEFT || keycode == KEY_RIGHT)
		rotation_or_move_key(keycode, fdf);
	else if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		zoom_or_projection_key(keycode, fdf);
	else if (keycode == KEY_O || keycode == KEY_I)
		zoom_or_projection_key(keycode, fdf);
	else if (keycode == KEY_R)
		reset_key(keycode, fdf);
	else if (keycode == KEY_Z || keycode == KEY_X)
		z_ratio_key(keycode, fdf);
	drawing(fdf);
	return (0);
}
