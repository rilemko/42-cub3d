/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_src_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:18:50 by mconreau          #+#    #+#             */
/*   Updated: 2023/06/22 20:42:06 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_src	*ft_src_get(t_app *app, const char *token)
{
	t_lst	*lst;

	lst = app->_srcs;
	while (lst != NULL)
	{
		if (ft_strcmp(((t_src *) lst->content)->token, token) == 0)
			return (lst->content);
		lst = lst->next;
	}
	return (NULL);
}
