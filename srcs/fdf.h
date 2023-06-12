/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 05:14:20 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/16 05:45:30 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define BUFFER_SIZE 42

# include <stdlib.h>
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <math.h>

# define WIN_WIDTH			1280
# define WIN_HEIGHT			960

# define PRESS_RED_BUTTON	17
# define KEY_ESC			53
# define KEY_W				13
# define KEY_S				1
# define KEY_A				0
# define KEY_D				2
# define KEY_Q				12
# define KEY_E				14
# define KEY_UP				126
# define KEY_DOWN			125
# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_PLUS			24
# define KEY_MINUS			27
# define KEY_O				31
# define KEY_I				34	
# define KEY_Z				6
# define KEY_X				7
# define KEY_R				15

/*for init point*/
typedef struct s_coord
{
	double		x;
	double		y;
	double		z;
}				t_coord;

/*for map_parsing*/
typedef struct s_map
{
	int			width;
	int			height;
	int			x_origin;
	int			y_origin;
	double		x_gap;
	double		y_gap;
	double		z_gap;
}				t_map;

/*for drawing*/
typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;

/*for drawing*/
typedef struct s_delta
{
	int			dx;
	int			dy;
}				t_delta;

/*for rotation*/
typedef struct s_angle
{
	double		alpha;
	double		beta;
	double		gamma;
}				t_angle;

/*for translate*/
typedef struct s_offset
{
	double		x;
	double		y;
	double		z;
	double		zoom;
}				t_offset;

/*data bundle*/
typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_coord		**coords;
	void		*img;
	void		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	t_angle		angle;
	t_offset	offset;
	int			projection_flag;
	int			z_ratio;
}				t_fdf;

/*main.c*/
void			init_angle(t_fdf *fdf);

/*GNL*/
char			*get_next_line(int fd);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);

/*drawing.c*/
void			drawing(t_fdf *fdf);

/*draw_line.c*/
void			draw_line(t_point s, t_point f, t_fdf *fdf);

/*init_points.c*/
t_point			**set_point_coord(t_fdf *fdf);

/*init_fdf*/
void			init_fdf(t_fdf *fdf);
void			init_angle(t_fdf *fdf);
void			init_offset(t_fdf *fdf);

/*read*/
void			read_file(t_fdf *fdf, char *path);

/*init_map_info*/
void			init_map_info(t_fdf *fdf, char *path);

/*init_coord*/
void			init_coords(t_fdf *fdf, char *path);

/*UTILS*/
char			**ft_split(char const *s, char c);
int				ft_atoi(char *str);
int				ft_abs(int n);
void			print_error(char *str);

/*rotatation*/
void			x_rotation(t_point *point, double angle);
void			y_rotation(t_point *point, double angle);
void			z_rotation(t_point *point, double angle);

/*key_press*/
int				key_press(int keycode, t_fdf *fdf);

/*close_win*/
int				close_win(t_fdf *fdf);

#endif
