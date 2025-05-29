/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_src_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:18:50 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/02 20:20:41 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_rgb	*ft_src_rgb(t_app *app, int code)
{
	t_lst	*lst;

	lst = app->_srcs;
	while (lst != NULL)
	{
		if (((t_src *) lst->content)->code == code)
			return (&((t_src *) lst->content)->rgb);
		lst = lst->next;
	}
	return (NULL);
}
