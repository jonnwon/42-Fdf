/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 04:59:59 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/16 15:17:08 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
		print_error("File input error\n");
	init_fdf(&fdf);
	read_file(&fdf, argv[1]);
	drawing(&fdf);
	mlx_hook(fdf.win, 2, 0, key_press, &fdf);
	mlx_hook(fdf.win, PRESS_RED_BUTTON, 0, close_win, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
