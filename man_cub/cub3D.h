/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-ouis <kid-ouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:39:22 by kid-ouis          #+#    #+#             */
/*   Updated: 2024/12/26 16:11:05 by kid-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <math.h>
# include <unistd.h>

# define WIN_WIDTH	1280
# define WIN_HEIGHT	720
# define SZ_TILE	100
# define NM_RAYS	WIN_WIDTH

# define TEX_WIDTH SZ_TILE
# define TEX_HEIGHT SZ_TILE

typedef struct s_mapinfos
{
	int	pi_lc;
	int	ni_lc;
	int	lines;
	int	j;
	int	lc;
}	t_mapinfos;

typedef struct s_char
{
	float	x;
	float	y;
	float	rad;
	float	turn_d;
	float	walk_d;
	float	move_d;
	float	rot_angle;
	float	pl_speed;
	float	rot_speed;
	int		color;
	int		wal;
	float	n_w;
	float	m_w;
}	t_char;

typedef struct s_line
{
	float	ray_ang;
	float	hwall_x;
	float	hwall_y;
	float	vwall_x;
	float	vwall_y;
	float	h_step_x;
	float	h_step_y;
	float	v_step_x;
	float	v_step_y;
	float	dst_h;
	float	dst_v;
	float	dst;
	float	ind_x;
	float	ind_y;
	int		vertical_hit;
	int		horizontal_hit;
	float	ray_up;
	float	ray_down;
	float	ray_left;
	float	ray_right;
}	t_line;

typedef struct s_var
{
	int		n;
	int		top_g;
	int		offsetx;
	int		offsety;
	int		bottom_g;
	int		img_w;
	int		img_h;
	int		stripheight;
	float	x;
	float	y;
}	t_var;

typedef struct s_stc
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			f[3];
	int			c[3];
	char		**map;
	int			index;
	char		r;
	char		*tmp_map;
	t_mapinfos	*mpinf;
	int			nm_row;
	int			nm_col;
	int			fire;
	int			sz;
	t_char		player;
	t_line		*rays;
	mlx_t		*mlx_pt;
	mlx_image_t	*img_pt;
	mlx_image_t	*img_no;
	mlx_image_t	*img_so;
	mlx_image_t	*img_ea;
	mlx_image_t	*img_we;
}	t_stc;

typedef struct s_up
{
	float	x;
	float	y;
	float	o;
	float	distance;
	float	prog;
	int		d;
}	t_up;

typedef struct s_rp
{
	float	inter_x;
	float	inter_y;
	float	vz_x;
	float	vz_y;
	float	hz_x;
	float	hz_y;
	float	check_x;
	float	check_y;
}	t_rp;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strjoin(char *s1, char *s2);
char		**ft_split(const char *s, char c);
void		ft_free(char **str);
char		*ft_strdup1(char *s1);
int			check_stc(char *stc);
int			ft_atoi(const char *str, unsigned long result);
char		*ft_strtrim(char *s1, char *set, int i, int start);
t_stc		*initialize_stc(void);
int			init_char(t_char *pl, t_stc *stc, mlx_t *mlx_ptr,
				mlx_image_t *img_pt);
int			check_line(char *line, t_stc *stc, int *i, char *linetrim);
int			map_components(char *line, t_stc *stc, int *index);
int			check_range(char *s);
void		ft_free(char **str);
int			num_cols(char **str);
float		ft_get_val(float angle);
t_mapinfos	*intial_mpinfos(t_stc *stc);
int			check_map(t_stc *stc, int i, t_mapinfos *mpinfos);
int			fill_no(t_stc *stc, char *line, int *index);
int			fill_so(t_stc *stc, char *line, int *index);
int			fill_we(t_stc *stc, char *line, int *index);
int			fill_ea(t_stc *stc, char *line, int *index);
int			fill_f(t_stc *stc, char **elements, int *index, char **range);
int			fill_c(t_stc *stc, char **elements, int *index, char **range);
int			ft_rgb(int r, int g, int b, int a);
void		ft_move(void *st);
void		render_game(t_stc *stc, int n, int m, float x);
float		get_angle(char c);
int			in_wall(t_stc *stc, float x, float y);
void		ft_rays_casting(t_stc *stc);
void		ft_walls_render(t_stc *stc);
void		update_player(t_stc *stc);
void		change_pos(t_stc *stc);
void		mouse_move(t_stc *stc);
int			in_wall_2(t_stc *stc, float x, float y);
float		calc_dst(float x0, float y0, float x1, float y1);
float		ft_get_val(float angle);
void		ft_casting(t_stc *stc, int id);
int			path_len(char *line, int *start, int i, int len);
char		*get_path(char *line, int start, int len, int i);
int			num_cols(char **str);
void		hz_ray(t_stc *stc, t_line *line);
void		vr_ray(t_stc *stc, t_line *line);
void		find_walls(t_stc *stc, t_line *line);
int			get_img_width(t_stc *stc, float ray_ang, int id);
int			get_img_height(t_stc *stc, float ray_ang, int id);
mlx_image_t	*get_img_pexel(t_stc *stc, float ray_ang, int id);
void		get_offset_x(t_stc *stc, t_var *vars, int id);
uint32_t	to_argb(uint32_t color);
int			check_nplayer(t_stc *stc);
void		clean_stc(t_stc *stc);
void		draw_outline_2(t_stc *stc, int x, int y, int color);
void		vr_while(t_stc *stc, t_line *line, t_rp vs);
void		hz_while(t_stc *stc, t_line *line, t_rp vs);
void		dst_check1(t_line *line);
void		dst_check2(t_line *line);
#endif