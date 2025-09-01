/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_abort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:58:56 by mconreau          #+#    #+#             */
/*   Updated: 2023/06/28 01:15:37 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_process_lne(t_app *app);
static void	ft_process_pth(t_app *app);
static void	ft_process_ptr(t_app *app);

/*
*	ft_parse_abort() :
*
*	Initiate parsing shutdown. The parsing process will finish the tasks
*	in progress and return control to the main process so that it also
*	terminate.
*/
t_rt	ft_parse_abort(t_app *app, double code)
{
	if (app->ext.is_set == FALSE)
	{
		ft_strlcpy(app->ext.content, "Error\n", MAX_BUFF_SIZE);
		ft_strlcat(app->ext.content, app->_, MAX_BUFF_SIZE);
		ft_strlcat(app->ext.content, " : ", MAX_BUFF_SIZE);
		ft_process_pth(app);
		ft_strlcat(app->ext.content, ft_err_use(app, code), MAX_BUFF_SIZE);
		ft_strlcat(app->ext.content, "\n", MAX_BUFF_SIZE);
		ft_process_lne(app);
		ft_process_ptr(app);
		app->ext.code = EXIT_FAILURE;
		app->ext.is_set = TRUE;
		app->prs.sts.is_running = FALSE;
	}
	return (FAILURE);
}

static void	ft_process_lne(t_app *app)
{
	char	*number;

	if (app->prs.ptr.pos_y > -1)
	{
		ft_strlcat(app->ext.content,
			ft_ternary(app->prs.ptr.pos_y > 9, " ", "  "), MAX_BUFF_SIZE);
		number = ft_itoa(app->prs.ptr.pos_y);
		ft_strlcat(app->ext.content, number, MAX_BUFF_SIZE);
		ft_free((void *) number);
		ft_strlcat(app->ext.content, " | ", MAX_BUFF_SIZE);
		ft_strlcat(app->ext.content, app->prs.new.buffer, MAX_BUFF_SIZE);
		ft_strlcat(app->ext.content, "\n", MAX_BUFF_SIZE);
	}
}

static void	ft_process_pth(t_app *app)
{
	char	*number;

	ft_strlcat(app->ext.content, "\"", MAX_BUFF_SIZE);
	ft_strlcat(app->ext.content, TERM_BCOLOR_WHT, MAX_BUFF_SIZE);
	ft_strlcat(app->ext.content, app->prs.ptr.filename, MAX_BUFF_SIZE);
	ft_strlcat(app->ext.content, TERM_CTRL_RESET, MAX_BUFF_SIZE);
	ft_strlcat(app->ext.content, "\"", MAX_BUFF_SIZE);
	if (app->prs.ptr.pos_y > -1)
	{
		ft_strlcat(app->ext.content, ":", MAX_BUFF_SIZE);
		number = ft_itoa(app->prs.ptr.pos_y);
		ft_strlcat(app->ext.content, number, MAX_BUFF_SIZE);
		ft_free((void *) number);
		ft_strlcat(app->ext.content, ":", MAX_BUFF_SIZE);
		number = ft_itoa(app->prs.ptr.pos_x + 1);
		ft_strlcat(app->ext.content, number, MAX_BUFF_SIZE);
		ft_free((void *) number);
	}
	ft_strlcat(app->ext.content, " : ", MAX_BUFF_SIZE);
}

static void	ft_process_ptr(t_app *app)
{
	if (app->prs.ptr.pos_y > -1)
	{
		ft_strlcat(app->ext.content, "    | ", MAX_BUFF_SIZE);
		while (app->prs.ptr.pos_x-- > 0)
			ft_strlcat(app->ext.content, " ", MAX_BUFF_SIZE);
		ft_strlcat(app->ext.content, TERM_BCOLOR_RED, MAX_BUFF_SIZE);
		ft_strlcat(app->ext.content, "^", MAX_BUFF_SIZE);
		ft_strlcat(app->ext.content, TERM_CTRL_RESET, MAX_BUFF_SIZE);
		ft_strlcat(app->ext.content, "\n", MAX_BUFF_SIZE);
	}
}
