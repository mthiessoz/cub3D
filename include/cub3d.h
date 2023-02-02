/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:25:40 by ggentil           #+#    #+#             */
/*   Updated: 2023/01/31 16:09:31 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>
# include "../utils/libft/libft.h"
# include "../utils/mlx/mlx.h"

# define WIN_X		1920
# define WIN_Y		1080
# define MAP_SIZE	10
# define SPEED		0.1
# define ROT_SPEED	0.05
# define LEFT_KEY	123
# define RIGHT_KEY	124
# define UP_KEY		126
# define DOWN_KEY	125
# define A_KEY		0
# define S_KEY		1
# define D_KEY		2
# define W_KEY		13
# define ESC		53
# define RED 		0x00FF0000
# define YEL 		0x00FFFF00
# define GREEN 		0x003AFF00
# define GRE 		0x00808080
# define BLU 		0x00002EFF
# define WHI 		0x00FFFFFF
# define SKY		0x059EA5 

typedef struct s_imgptr
{
	char	*path;
	void	*img;
	int		width;
	int		height;
	int		*px;
	int		bytes;
	int		line;
	int		end;
}	t_imgptr;

typedef struct s_ray
{
	double	camera_x;
	double	pos_x;
	double	pos_y;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	double	dir_x;
	double	dir_y;
	float	plane_x;
	float	plane_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	int		height;
	int		width;
	double	tex_pos;
}	t_ray;

typedef struct s_line
{
	int	drawstart;
	int	drawend;
	int	height;
	int	width;
}	t_line;

typedef struct s_img
{
	char	*img_path;
	int		img_height;
	int		img_width;
	int		*pxs;
	int		bits;
	int		s_line;
	int		end;
	void	*img;
}	t_img;

typedef struct s_asset
{
	char	*path;
	int		r;
	int		g;
	int		b;
	int		nb_nswe;
	int		nb_color;
	char	**nswe;
	char	**color;
	t_img	*no;
	t_img	*so;
	t_img	*we;
	t_img	*ea;

}	t_asset;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	t_imgptr	*img;
	int			x_map;
	int			y_map;
	char		**map;
	char		*map_path;
	int			map_height;
	int			map_width;
	float		ppos_x;
	float		ppos_y;
	int			len_map;
	int			nb_line;
	int			tablen;
	int			player_count;
	char		player_direction;
	float		pdir_x;
	float		pdir_y;
	int			player_x;
	int			player_y;
	int			floor;
	int			ceiling;
	t_asset		*asset;
	t_ray		*ray;
	t_line		*line;
}	t_data;

//map_check
int		check_map_char(t_data *dt);
int		check_borders(t_data *dt);
int		check_player(t_data *dt);
void	check_borders_debut(t_data *dt);
void	check_borders_la_suite(t_data *dt);

//map_utils
int		replace_space_by_wall(t_data *dt);
void	empty_map(t_data *dt);
void	no_player(t_data *dt);
void	multiple_players(t_data *dt);
void	asset_utils(t_data *dt);

//read_map
int		nb_of_asset(char *line);
int		read_map(t_data *data);
int		nb_line(t_data *dt, int number, int fd);
int		error_map(t_data *dt, int fd);
int		read_map_utils(t_data *dt);

//parsing_file
int		parse_file(t_data *dt, char *line, int i);
int		parse_nswe(t_data *dt, char *line, int i);
int		parse_color(t_data *dt, char *line, int i);
int		parse_map(t_data *dt, char *line, int i);
int		error_asset(t_data *dt);

//error_args
int		error_args(int argc, char **argv);
int		check_cub(char *c);

//init
int		init_game(t_data *dt);
int		init_asset(t_data *dt);
void	init_file(t_data *dt, int fd);
void	init_map(t_data *dt);

//minimap
int		minimap_display(t_data *dt);
void	minimap_printer(t_data *dt, int i, int j, char c);
void	my_pixel(t_data *dt, int x, int y, int color);
void	my_square_pixel(t_data *dt, int x, int y, int color);
void	my_player_pixel(t_data *dt, int x, int y, int color);

//raycasting
void	perform_dda(t_data *dt);
int		raycasting(t_data *dt);
void	side_coloring(t_data *dt);

//raycasting_utils
int		screen_display(t_data *dt);
void	hit_wall(t_data *dt);
void	calcul_perp_distance(t_data *dt);
void	calcul_stripe_to_fill(t_data *dt);
int		draw_ver_line(t_data *dt, int x);

//raycasting_init
void	calcul_side_distance(t_data *dt);
void	calcul_ray_pos_dir(t_data *dt, int x);
void	init_ray(t_data *dt);
void	init_player_pos_dir(t_data *dt);

//check_asset
int		check_path(t_data *dt);
int		check_valid_path(t_data *dt, char *line);
void	check_valid_path2(t_data *dt, char *line);
int		check_color(t_data *dt, char *line);
int		parse_color2(t_data *dt, char *line);

//check_asset_utils
int		atoi_color(t_data *dt, char **color, char what);
int		check_virgule(char *line);
void	calloc_asset(t_data *dt);
void	error_color(char *line);

//exit
int		exit_game(t_data *dt);
void	exit_dt(t_data *dt);
void	exit_asset(t_asset *asset);
void	exit_img(t_img *img);
void	exit_more(t_data *dt);

//free
void	free_tmp(char **tmp);
void	check_nb_color(t_data *dt, char **tmp);

//errors
int		errorminator(t_data *dt, char **args);

//moves
int		where_to_go(int keycode, t_data *dt);
int		straight_move(t_data *dt);
int		back_move(t_data *dt);
int		right_move(t_data *dt);
int		left_move(t_data *dt);

//rotate
void	rot_left(t_data *dt);
void	rot_right(t_data *dt);

//player
void	player_display(t_data *dt);
void	pixel_player(t_data *dt);
void	init_dir_player(t_data *dt);
void	ray_display(t_data *dt);
int		move_start(t_data *dt, float dist);

//trgb
int		create_trgb(int r, int g, int b);

//textures
void	init_assets(t_asset *asset);
int		which_texture(t_data *dt, int i);
void	text_init(t_data *dt);
void	put_texture(t_data *dt, t_ray *ray, int x);
int		where_texture(t_data *dt, t_ray *ray);

#endif