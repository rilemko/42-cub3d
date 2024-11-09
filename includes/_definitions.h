/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _definitions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:10:06 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/25 16:51:20 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "_constants.h"

typedef struct s_app	t_app;
typedef int				t_bool;
typedef int				t_bt;
typedef int				t_fd;
typedef mlx_image_t		t_m_img;
typedef mlx_key_data_t	t_m_key;
typedef mlx_texture_t	t_m_tex;
typedef int				t_rt;

typedef struct s_arg
{
	char				**agv;
	char				**env;
}	t_arg;

typedef struct s_cfg
{
	t_bool				collision;
	double				delay_animation;
	double				delay_hooks_key;
	double				delay_hooks_ptr;
	const char			*folder_maps;
	const char			*folder_srcs;
	const char			*format_maps;
	const char			*format_srcs;
	size_t				fov;
	size_t				hud_opacity;
	size_t				hud_offsets;
	size_t				hud_size_def;
	size_t				ratio_actionuse;
	double				ratio_depthblur;
	double				ratio_gradients;
	double				ratio_hud_zooms;
	double				ratio_mousemove;
	double				ratio_speed_run;
	size_t				ratio_texturing;
	double				speed_movements;
	double				speed_rotations;
	size_t				win_size_h;
	size_t				win_size_w;
}	t_cfg;

typedef struct s_dst
{
	double				dist_h;
	double				dist_hx;
	double				dist_hz;
	double				dist_v;
	double				dist_vx;
	double				dist_vz;
}	t_dst;

typedef struct s_err
{
	double				code;
	char				content[MAX_BUFF_SIZE];
}	t_err;

typedef struct s_ext
{
	int					code;
	char				content[MAX_BUFF_SIZE];
	t_bool				is_set;
}	t_ext;

typedef struct s_hud
{
	double				map_offset;
	size_t				map_pos_x;
	size_t				map_pos_y;
	size_t				map_sizing;
	size_t				map_sizing_d2;
}	t_hud;

typedef struct s_key
{
	void				(*callback)(t_app *, t_bool);
	int					code;
	t_bool				is_pressed;
}	t_key;

typedef struct s_lne
{
	char				buffer[MAX_BUFF_SIZE];
	int					length;
}	t_lne;

typedef struct s_mlx
{
	mlx_t				*mlx;
	double				timestamp;
}	t_mlx;

typedef struct s_pos
{
	double				pos_x;
	double				pos_z;
}	t_pos;

typedef struct s_map
{
	char				buffer[MAX_BUFF_SIZE];
	char				**map;
	size_t				size_h;
	size_t				size_w;
}	t_map;

typedef struct s_gme
{
	double				angle;
	t_bool				collision;
	double				speed_movements;
	double				speed_rotations;
	double				target_dst;
	t_pos				target_pos;
	t_pos				dot;
	t_map				map;
	t_pos				pos;
}	t_gme;

typedef struct s_ptr
{
	t_fd				file_descriptor;
	char				filename[MAX_PATH_SIZE];
	int					pos_x;
	int					pos_y;
}	t_ptr;

typedef struct s_spr
{
	double				distance;
	double				ply_angle;
	double				fov_angle;
	double				total_h;
	t_pos				dot;
	t_pos				pos;
	t_pos				pos_s;
}	t_spr;

typedef struct s_sts
{
	t_bool				is_running;
}	t_sts;

typedef struct s_prs
{
	size_t				count_index;
	size_t				count_total;
	t_bool				is_complete;
	t_lne				new;
	t_lne				nxt;
	t_lne				old;
	t_ptr				ptr;
	t_sts				sts;
}	t_prs;

typedef struct s_ray
{
	double				angle;
	size_t				count;
	double				distance;
	t_bool				hit;
	double				*hits;
	double				offset_t;
	double				offset_x;
	double				offset_y;
	int					target_tpe;
	t_dst				dst;
	t_pos				map;
	t_pos				pos;
}	t_ray;

typedef struct s_hok
{
	size_t				count;
	double				key_checked_at;
	double				ptr_checked_at;
	double				key_catched_at;
}	t_hok;

typedef struct s_rdr
{
	t_lst				*_sprs;
	double				animate_at;
	uint8_t				*content;
	t_bool				is_updated;
	double				screen_dst;
	double				updated_at;
	t_hud				hud;
	t_ray				ray;
	t_sts				sts;
}	t_rdr;

typedef struct s_rgb
{
	double				byte_h;
	double				byte_l;
	double				channel_a;
	double				channel_b;
	double				channel_g;
	double				channel_r;
}	t_rgb;

typedef struct s_drw
{
	size_t				index_1;
	size_t				index_2;
	double				ratio_depth;
	double				ratio_scale;
	size_t				s;
	size_t				s_d2;
	t_pos				pos_s;
	t_pos				pos_t;
	t_rgb				rgb;
}	t_drw;

typedef struct s_src
{
	t_lst				*_texs;
	void				(*callback)(t_app *, struct s_src *);
	int					code;
	size_t				count_total;
	t_bool				is_set;
	char				token[MAX_CODE_SIZE];
	t_rgb				rgb;
}	t_src;

typedef struct s_tkn
{
	int					code;
	size_t				count_index;
	t_bool				is_colored;
	char				token[MAX_CODE_SIZE];
	t_rgb				rgb;
}	t_tkn;

typedef struct s_win
{
	size_t				bytes_total;
	size_t				bytes_width;
	t_m_img				*canvas;
	size_t				framerate;
	t_bool				is_opened;
	size_t				size_h;
	size_t				size_w;
	size_t				size_h_d2;
	size_t				size_w_d2;
	size_t				tick_count;
	double				tick_delta;
	char				title[MAX_CODE_SIZE];
}	t_win;

typedef struct s_app
{
	const char			*_;
	t_lst				*_errs;
	t_lst				*_keys;
	t_lst				*_rdrs;
	t_lst				*_srcs;
	t_lst				*_tkns;
	t_arg				arg;
	t_cfg				cfg;
	t_ext				ext;
	t_gme				gme;
	t_hok				hok;
	t_mlx				mlx;
	t_prs				prs;
	t_rdr				rdr;
	t_spr				spr;
	t_sts				sts;
	t_win				win;
}	t_app;
