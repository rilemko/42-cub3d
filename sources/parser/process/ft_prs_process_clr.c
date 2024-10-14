/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prs_process_clr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:23:39 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/24 22:41:56 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_rt	ft_precheck(t_app *app, t_src *src, char **array);
static void	ft_process(t_app *app, t_src *src, const char *content);

/*
*	ft_prs_process_clr() :
*
*
*/
void	ft_prs_process_clr(t_app *app, t_src *src)
{
	char	**array;

	array = ft_split(&app->prs.new.buffer[app->prs.ptr.pos_x], ',');
	while (array[src->count_total] && app->prs.sts.is_running == TRUE)
	{
		if (ft_precheck(app, src, array) == SUCCESS)
		{
			ft_process(app, src, array[src->count_total]);
			app->prs.ptr.pos_x += ft_strlen(array[src->count_total++]) + 1;
		}
	}
	src->count_total = 0;
	ft_free_deep((void **) array);
}

static t_rt	ft_precheck(t_app *app, t_src *src, char **array)
{
	if (src->count_total < 2 && array[src->count_total + 1] == NULL)
		return (ft_parse_abort(app, 2.09));
	if (src->count_total == 3)
		return (ft_parse_abort(app, 2.10));
	return (SUCCESS);
}

static void	ft_process(t_app *app, t_src *src, const char *content)
{
	int	channel;

	channel = ft_atoi(content);
	while (*content)
		if (ft_isdigit(*content++) == FALSE)
			return ((void) ft_parse_abort(app, 2.11));
	if (channel < 0 || channel > 255)
		return ((void) ft_parse_abort(app, 2.12));
	if (src->count_total == 0)
		src->rgb.channel_r = channel;
	else if (src->count_total == 1)
		src->rgb.channel_g = channel;
	else if (src->count_total == 2)
		src->rgb.channel_b = channel;
	src->rgb.byte_h = ft_color_byte_h(&src->rgb);
	src->rgb.byte_l = ft_color_byte_l(&src->rgb);
}
