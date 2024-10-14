/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upd_process_hok.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 01:35:38 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/25 15:58:32 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_upd_process_hok(t_app *app)
{
	t_lst	*lst;

	if (app->hok.count > 0 && app->mlx.timestamp - app->hok.key_checked_at
		>= app->cfg.delay_hooks_key)
	{
		lst = app->_keys;
		while (lst != NULL)
		{
			if (((t_key *) lst->content)->is_pressed == TRUE)
			{
				((t_key *) lst->content)->callback(app, TRUE);
				app->rdr.is_updated = FALSE;
			}
			lst = lst->next;
		}
		app->hok.key_checked_at = app->mlx.timestamp;
	}
}
