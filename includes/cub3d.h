/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:09:19 by mconreau          #+#    #+#             */
/*   Updated: 2024/10/11 00:45:23 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "_includes.h"
#include "_definitions.h"

// APPLICATION /////////////////////////////////////////////////////////////////

t_rt	ft_app_abort(t_app *app, double code);
void	ft_app_exit(t_app *app, int code, const char *content);
void	ft_app_exit_failure(t_app *app, const char *content);
void	ft_app_exit_success(t_app *app, const char *content);

// BOOTSTRAPPER ////////////////////////////////////////////////////////////////

void	ft_bootstrap(t_app *app);
void	ft_bot_process_err(t_app *app);
void	ft_bot_process_key(t_app *app);
void	ft_bot_process_rdr(t_app *app);
void	ft_bot_process_src(t_app *app);
void	ft_bot_process_tkn(t_app *app);

// COLORS //////////////////////////////////////////////////////////////////////

double	ft_color_byte_h(t_rgb *rgb);
double	ft_color_byte_l(t_rgb *rgb);
void	ft_color_lighten(t_rgb *rgb, double percentage);
void	ft_color_darken(t_rgb *rgb, double percentage);
int		ft_color_toint(int r, int g, int b);

void	ft_canvas_darken(t_app *app, size_t x, size_t y, double percentage);
void	ft_canvas_lighten(t_app *app, size_t x, size_t y, double percentage);
void	ft_canvas_pixel_get(t_app *app, t_rgb *rgb, size_t x, size_t y);
void	ft_canvas_pixel_set(t_app *app, t_rgb *rgb, size_t x, size_t y);

// FILESYSTEM //////////////////////////////////////////////////////////////////

t_rt	ft_close(t_fd file_descriptor);
t_bool	ft_exists(const char *filename);
t_rt	ft_fopen(const char *filename, t_fd *file_descriptor, const char *mode);
t_rt	ft_fread(const char *filename, char *buffer);
t_rt	ft_open(const char *filename, t_fd *file_descriptor, int flags);
t_bt	ft_read(t_fd file_descriptor, char *buffer, char delimiter, int size);
t_rt	ft_write(t_fd file_descriptor, const char *content);

// GAME ////////////////////////////////////////////////////////////////////////

void	ft_game_move_axe(t_app *app, double pos_x);
void	ft_game_move_pos(t_app *app, double pos_x, double pos_z);
void	ft_game_move_run(t_app *app, double scale);
void	ft_game_move_use(t_app *app);
void	ft_game_swap_map(t_app *app, double scale);

// HOOKER //////////////////////////////////////////////////////////////////////

void	ft_hook(t_m_key input, void *app);
void	ft_hok_process_065(t_app *app, t_bool is_pressed);
void	ft_hok_process_068(t_app *app, t_bool is_pressed);
void	ft_hok_process_069(t_app *app, t_bool is_pressed);
void	ft_hok_process_077(t_app *app, t_bool is_pressed);
void	ft_hok_process_082(t_app *app, t_bool is_pressed);
void	ft_hok_process_083(t_app *app, t_bool is_pressed);
void	ft_hok_process_087(t_app *app, t_bool is_pressed);
void	ft_hok_process_256(t_app *app, t_bool is_pressed);
void	ft_hok_process_262(t_app *app, t_bool is_pressed);
void	ft_hok_process_263(t_app *app, t_bool is_pressed);

// MATH ////////////////////////////////////////////////////////////////////////

double	ft_hypot(double xa, double ya, double xb, double yb);

// PARSER //////////////////////////////////////////////////////////////////////

t_rt	ft_parse(t_app *app);
t_rt	ft_parse_abort(t_app *app, double code);
t_rt	ft_parse_open(t_app *app);
void	ft_parse_path(char *buffer, const char *prefix, const char *filename);
t_rt	ft_parse_read(t_app *app);
void	ft_parse_reap(t_app *app, char *buffer);
void	ft_parse_skip(t_app *app, t_bool inner);
void	ft_prs_process_clr(t_app *app, t_src *src);
void	ft_prs_process_map(t_app *app, t_src *src);
void	ft_prs_process_tex(t_app *app, t_src *src);

// RENDERER ////////////////////////////////////////////////////////////////////

void	ft_render(t_app *app);

void	ft_render_00(t_app *app);
void	ft_r00_process_cel(t_app *app, t_rgb *rgb);
void	ft_r00_process_flr(t_app *app, t_rgb *rgb);

void	ft_render_01(t_app *app);
void	ft_r01_process_col(t_app *app);
void	ft_r01_process_spr(t_app *app);

void	ft_raycasting_loop(t_app *app, t_ray *ray, t_gme *gme);
void	ft_verticals_rays(t_app *app, t_ray *ray, t_gme *gme);
void	ft_horizontal_rays(t_app *app, t_ray *ray, t_gme *gme);
double	ft_fix_angle(double angle);

void	ft_render_02(t_app *app);
void	ft_r02_process_map(t_app *app);
void	ft_r02_process_ptr(t_app *app);

// RESOURCES ///////////////////////////////////////////////////////////////////

t_err	*ft_err_add(t_app *app, double code, const char *content);
t_err	*ft_err_get(t_app *app, double code);
char	*ft_err_use(t_app *app, double code);

t_key	*ft_key_add(t_app *app, int code, void (*callback)(t_app *, t_bool));
t_key	*ft_key_get(t_app *app, int code);

t_spr	*ft_spr_add(t_app *app, t_pos *pos);
t_spr	*ft_spr_get(t_app *app, t_pos *pos);

t_src	*ft_src_add(t_app *app, int code, const char *token,
			void (*callback)(t_app *, struct s_src *));
t_src	*ft_src_get(t_app *app, const char *token);
t_rgb	*ft_src_rgb(t_app *app, int code);
uint8_t	*ft_src_use(t_app *app, int code);

t_tkn	*ft_tkn_add(t_app *app, int code, const char *token, int color);
t_tkn	*ft_tkn_get(t_app *app, char token);
int		ft_tkn_use(t_app *app, char token);

// STRUCTURES //////////////////////////////////////////////////////////////////

void	st_app_clear(t_app *app);
void	st_app_initialize(t_app *app, int agc, char **agv, char **env);
void	st_arg_clear(t_arg *arg);
void	st_arg_initialize(t_arg *arg, char **agv, char **env);
void	st_cfg_clear(t_cfg *cfg);
void	st_cfg_initialize(t_cfg *cfg);
void	st_drw_clear(t_drw *drw);
void	st_drw_initialize(t_drw *drw);
void	st_dst_clear(t_dst *dst);
void	st_dst_initialize(t_dst *dst);
void	st_err_clear(void *err);
void	st_err_initialize(t_err *err);
void	st_ext_clear(t_ext *ext);
void	st_ext_initialize(t_ext *ext);
void	st_gme_clear(t_gme *gme);
void	st_gme_initialize(t_gme *gme, t_cfg *cfg);
void	st_hok_clear(t_hok *hok);
void	st_hok_initialize(t_hok *hok);
void	st_hud_clear(t_hud *hud);
void	st_hud_initialize(t_hud *hud, t_cfg *cfg);
void	st_key_clear(void *key);
void	st_key_initialize(t_key *key);
void	st_lne_clear(t_lne *lne);
void	st_lne_initialize(t_lne *lne);
void	st_map_clear(t_map *map);
void	st_map_initialize(t_map *map);
void	st_mlx_clear(t_mlx *mlx);
void	st_mlx_initialize(t_mlx *mlx);
void	st_pos_clear(t_pos *pos);
void	st_pos_initialize(t_pos *pos);
void	st_prs_clear(t_prs *prs);
void	st_prs_initialize(t_prs *prs);
void	st_ptr_clear(t_ptr *ptr);
void	st_ptr_initialize(t_ptr *ptr);
void	st_ray_clear(t_ray *ray);
void	st_ray_initialize(t_ray *ray, t_gme *gme);
void	st_rdr_clear(t_rdr *rdr);
void	st_rdr_initialize(t_rdr *rdr, t_cfg *cfg, t_gme *gme);
void	st_rgb_clear(t_rgb *rgb);
void	st_rgb_initialize(t_rgb *rgb);
void	st_spr_clear(void *spr);
void	st_spr_initialize(t_spr *spr);
void	st_src_clear(void *src);
void	st_src_initialize(t_src *src);
void	st_sts_clear(t_sts *sts);
void	st_sts_initialize(t_sts *sts);
void	st_tkn_clear(void *tkn);
void	st_tkn_initialize(t_tkn *tkn);
void	st_win_clear(t_win *win);
void	st_win_initialize(t_win *win, t_cfg *cfg);

// SYSTEM //////////////////////////////////////////////////////////////////////

void	ft_exit(int code, const char *content);
void	ft_exit_failure(const char *content);
void	ft_exit_success(const char *content);

// TEXTURES ////////////////////////////////////////////////////////////////////

t_rgb	*ft_texture_pixel_get(t_app *app, uint8_t *texture, t_rgb *rgb,
			t_pos *pos);

// UPDATER /////////////////////////////////////////////////////////////////////

void	ft_update(t_app *app);
void	ft_upd_process_hok(t_app *app);
void	ft_upd_process_mlx(t_app *app);
void	ft_upd_process_ptr(t_app *app);
void	ft_upd_process_src(t_app *app);
void	ft_upd_process_win(t_app *app);

// WINDOWS /////////////////////////////////////////////////////////////////////

void	ft_window_close(t_app *app, t_win *win);
t_rt	ft_window_open(t_app *app, t_mlx *mlx, t_win *win);
