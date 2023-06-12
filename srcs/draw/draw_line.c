/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:23:38 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/16 05:04:08 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if ((0 <= x && x < WIN_WIDTH) && (0 <= y && y < WIN_HEIGHT))
	{
		dst = fdf->addr + (y * fdf->line_length + x * (fdf->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

static void	draw_case1(t_point s, t_point f, t_delta delta, t_fdf *fdf)
{
	int	p;
	int	add_1;
	int	add_2;

	add_1 = 2 * delta.dy;
	add_2 = 2 * (delta.dy - delta.dx);
	p = 2 * delta.dy - delta.dx;
	while (s.x != f.x)
	{
		my_mlx_pixel_put(fdf, s.x, s.y, s.color);
		if (p < 0)
			p += add_1;
		else
		{
			p += add_2;
			if (s.y < f.y)
				s.y++;
			else
				s.y--;
		}
		if (s.x < f.x)
			s.x++;
		else
			s.x--;
	}
}

static void	draw_case2(t_point s, t_point f, t_delta delta, t_fdf *fdf)
{
	int	p;
	int	add_1;
	int	add_2;

	add_1 = 2 * delta.dx;
	add_2 = 2 * (delta.dx - delta.dy);
	p = 2 * delta.dx - delta.dy;
	while (s.y != f.y)
	{
		my_mlx_pixel_put(fdf, s.x, s.y, s.color);
		if (p < 0)
			p += add_1;
		else
		{
			p += add_2;
			if (s.x < f.x)
				s.x++;
			else
				s.x--;
		}
		if (s.y < f.y)
			s.y++;
		else
			s.y--;
	}
}

void	draw_line(t_point s, t_point f, t_fdf *fdf)
{
	t_delta	delta;

	delta.dx = ft_abs(f.x - s.x);
	delta.dy = ft_abs(f.y - s.y);
	if (delta.dx >= delta.dy)
		draw_case1(s, f, delta, fdf);
	else
		draw_case2(s, f, delta, fdf);
}
