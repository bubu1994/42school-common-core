/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:32:52 by sbaumann          #+#    #+#             */
/*   Updated: 2025/03/11 08:52:42 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <sys/time.h>
# include <math.h>
# include <stdbool.h>
# include "../libft/libft.h"

# ifdef __APPLE__
#  include "../mlx_macos/mlx.h"
#  define ESC_K 53
#  define LEFT_A 123
#  define RIGHT_A 124
#  define S 1
#  define W 13
#  define A 0
#  define D 2
#  define M 46
#  define N 45
#  define B 11
#  define I 34
#  define O 31
#  define E 14
#  define R 15
# elif defined(__linux__)
#  include "../mlx-linux/mlx.h"
#  include <X11/keysym.h>
#  define ESC_K 		65307
#  define LEFT_A 		65361
#  define RIGHT_A 		65363
#  define E 101
#  define R 114
#  define S 115
#  define A 97
#  define D 100
#  define W 119
#  define M 109
#  define N 110
#  define B 98
#  define I 105
#  define O 111
# endif

# define LEFT_A_STATE				254
# define RIGHT_A_STATE				255
# define MOUSE_STATE				253
# define MAX_MAP_SIZE				200
# define WIDTH 						1200
# define HEIGHT 					900
# define FOV						1.0471975512 // M_PI / 3.00
# define EDGE_GAP 					10
# define SPEED 						0.1
# define ROT_SPEED 					0.0872664626 // FOV / 12.00
# define SAFE_DISTANCE				0.19

/* COLORS */
# define GREY_WALLS 				0xA0A0A0
# define WHITE_FLOOR 				0xFFFFFF
# define LIGHT_GREY_GRID			0xD2D2D2
# define BLACK_RAYS					0x000000
# define RED_PLAYER					0xFF0000
# define MAGENTA_DEBUG				0xFF00FF

/* STRINGS */
# define INV_ARGS					"Invalid number of arguments"
# define XPM_LOAD_FAIL				"Failed to load XPM image"
# define MALLOC_FAIL				"Malloc failed"
# define INV_COLOR					"Invalid color component"
# define NO_PLAYER					"Player not found"
# define INV_CHAR					"Unexpected character encountered"
# define MAP_SIZE_ERR				"Excessive map size"
# define DUPLICATE_TEXTURE			"Texture encountered more than once"
# define DUPLICATE_COLOUR			"Colour encountered multiple times]"
# define TEXTURE_NOT_FOUND			"Texture not found"
# define COLOUR_NOT_FOUND			"Colour not found"
# define MAP_NOT_FOUND				"Map not found"
# define IMG_FAIL					"Failed to create image"
# define IMG_DATA_FAIL				"Failed to retrieve image data"

typedef struct s_data
{
	char							**map;
	unsigned int					ceiling_c;
	unsigned int					floor_c;
	int								w_map;
	int								h_map;
	int								m_scale;
}	t_data;

typedef struct s_cam
{
	int								mini_x;
	int								mini_y;
	double							x;
	double							y;
	double							angle;
	double							cos;
	double							sin;
}	t_cam;

typedef struct s_img
{
	void							*img_ptr;
	char							*img_pixels_ptr;
	int								bits_per_pixel;
	int								endian;
	int								line_len;
}	t_img;

typedef struct s_ray
{
	int								index;
	double							ang;
	double							length;
	double							dist_perp;
	double							hit_pos;
	double							hit_x;
	double							hit_y;
	char							face_hit;
	bool							door;
}	t_ray;

typedef struct s_tex_img
{
	void							*img_ptr;
	char							*img_pixels_ptr;
	int								width;
	int								height;
	int								bits_per_pixel;
	int								line_len;
	int								endian;
}	t_tex_img;

typedef struct s_tex
{
	char							*no;
	char							*so;
	char							*we;
	char							*ea;
	char							*door;
	t_tex_img						no_img;
	t_tex_img						so_img;
	t_tex_img						we_img;
	t_tex_img						ea_img;
	t_tex_img						door_img;
}	t_tex;

typedef struct s_enemy
{
	char							*monster_path;
	t_tex_img						monster_img;
	double							x;
	double							y;
	double							distance;
	int								visible;
}	t_enemy;

typedef struct s_calcul
{
	double							cos;
	double							sin;
	int								map_x;
	int								map_y;
	double							dist_w;
	double							dist_h;
	double							side_w;
	double							side_h;
	int								dir_x;
	int								dir_y;
	int								face;
}	t_cal;

typedef struct s_mlx
{
	void							*ptr;
	void							*window;
	t_img							image;
	t_cam							cam;
	t_data							scene;
	t_ray							rays[WIDTH];
	t_tex							textures;
	t_enemy							monster;
	int								mini_map_flag;
	int								fov_flag;
	int								grid_flag;
	int								keys[256];
	long							last_time;
	bool							bonus;
	int								mouse_pressed_x;
}	t_mlx;

/* MISC. */
void			init(t_mlx *cub);
int				load_textures(t_mlx *cub);
void			set_ray_data(t_mlx *cub, double ray_ang, t_cal *a, int i);
void			other_calculations(t_mlx *cub, t_cal *a);

/* PARSING */
int				parsing(t_mlx *cub, char *file_name);
int				parse_line(t_mlx *cub, char **split, char **line, int fd);
void			bonus_or_not_bonus(t_mlx *cub);
int				err_atoui(const char *str);
int				read_map(t_mlx *cub, int fd, char **line);
int				handle_color(unsigned int *color_data, char **split, char *fc);
int				line_is_spaces(const char *s);
int				find_map(t_mlx *cub, char *file);
int				build_map(t_mlx *cub, char **line, int fd);
int				flood_fill(t_mlx *cub, char ***map_copy, int y, int x);
int				find_player(t_mlx *cub, char **line_map, int y);
int				check_data(t_mlx *cub);

/* RENDERING */
int				track_mouse_and_rotate(t_mlx *cub);
void			update_movement(t_mlx *cub);
void			raycaster(t_mlx *cub);
void			wall_drawer(t_mlx *cub);
void			put_my_pixel(t_img *img, int x, int y, unsigned int color);
void			fill_floor_ceiling(t_mlx *cub);
int				get_pixel_color(t_mlx *cub, int x, int y);
unsigned int	get_texture_pixel(t_tex_img *texture, int x, int y);
void			minimap(t_mlx *cub);

/* HOOKS */
int				click_x(t_mlx *cub);
int				key_press(int key, t_mlx *cub);
int				key_release(int key, t_mlx *cub);
int				mouse_press(int button, int x, int y, t_mlx *cub);
int				mouse_release(int button, int x, int y, t_mlx *cub);

/* UTILS */
long			get_current_time(void);
void			destruct(t_mlx *cub);
void			array_free(char **arr);
void			print_arr(char **arr);
void			print_rays_data(t_mlx *cub);
int				ret_error(char *id, char *error);
void			print_data(t_mlx *cub);
char			**copy_arr(char **arr);
int				opti_scaling_minimap(t_data *scene);
int				valid_map_line(t_mlx *cub, const char *s);
double			extract_frac(double n);
int				is_in_safe_distance(t_cam *pos);

#endif