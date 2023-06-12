/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 23:40:01 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/16 02:51:19 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	init_map_width(t_fdf *fdf, char *line)
{
	char	**arr;
	int		cnt;

	arr = ft_split(line, ' ');
	cnt = 0;
	while (arr && arr[cnt])
	{
		free(arr[cnt]);
		cnt++;
	}
	free(arr);
	fdf->map.width = cnt;
}

static void	init_map_height(t_fdf *fdf, char *line, int fd)
{
	int	cnt;

	cnt = 1;
	while (1)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		cnt++;
	}
	fdf->map.height = cnt;
}

void	init_map_info(t_fdf *fdf, char *path)
{
	char	*line;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_error("file open error\n");
	line = get_next_line(fd);
	init_map_width(fdf, line);
	init_map_height(fdf, line, fd);
	fdf->map.x_origin = fdf->map.width / 2;
	fdf->map.y_origin = fdf->map.height / 2;
	close(fd);
}
