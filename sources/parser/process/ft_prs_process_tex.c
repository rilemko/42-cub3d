/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prs_process_tex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:23:39 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/30 21:09:48 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_rt	ft_precheck(t_app *app, const char *content);
static void	ft_process(t_app *app, t_src *src, const char *content);

/*
*	ft_prs_process_tex() :
*
*
*/
void	ft_prs_process_tex(t_app *app, t_src *src)
{
	char	buffer[MAX_PATH_SIZE];
	char	**array;

	array = ft_split(&app->prs.new.buffer[app->prs.ptr.pos_x], ',');
	while (array[src->count_total] && app->prs.sts.is_running == TRUE)
	{
		ft_bzero(buffer, MAX_PATH_SIZE);
		ft_parse_path(buffer, app->cfg.folder_srcs, array[src->count_total]);
		if (ft_precheck(app, buffer) == SUCCESS)
		{
			ft_process(app, src, buffer);
			app->prs.ptr.pos_x += ft_strlen(array[src->count_total++]) + 1;
		}
	}
	if (app->prs.sts.is_running == TRUE)
		ft_lstlast(src->_texs)->next = src->_texs;
	ft_free_deep((void **) array);
}

static t_rt	ft_precheck(t_app *app, const char *content)
{
	if (ft_strmatch(app->cfg.format_srcs, content) == FALSE)
		return (ft_parse_abort(app, 2.07));
	if (ft_exists(content) == FALSE)
		return (ft_parse_abort(app, 0.02));
	return (SUCCESS);
}

static void	ft_process(t_app *app, t_src *src, const char *content)
{
	t_m_tex	*texture;
	uint8_t	*pixels;

	texture = mlx_load_png(content);
	if (texture == NULL)
		return ((void) ft_parse_abort(app, 4.02));
	if (texture->height != app->cfg.ratio_texturing
		|| texture->width != app->cfg.ratio_texturing)
				return (src->count_total--, ft_parse_abort(app, 2.08),
					mlx_delete_texture(texture));
	pixels = malloc(app->cfg.ratio_texturing * app->cfg.ratio_texturing * 4);
	ft_memcpy(pixels, texture->pixels,
		app->cfg.ratio_texturing * app->cfg.ratio_texturing * 4);
	mlx_delete_texture(texture);
	ft_lstadd_back(&src->_texs, ft_lstnew(pixels));
}
