/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spr_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:18:50 by mconreau          #+#    #+#             */
/*   Updated: 2023/08/07 11:49:00 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_spr	*ft_spr_get(t_app *app, t_pos *pos)
{
	t_lst	*lst;

	lst = app->rdr._sprs;
	while (lst != NULL)
	{
		if ((((t_spr *) lst->content)->dot.pos_x == pos->pos_x
				&& ((t_spr *) lst->content)->dot.pos_z == pos->pos_z))
			return (lst->content);
		lst = lst->next;
	}
	return (NULL);
}
