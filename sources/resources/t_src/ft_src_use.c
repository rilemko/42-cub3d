/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_src_use.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:18:50 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/03 17:16:18 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint8_t	*ft_src_use(t_app *app, int code)
{
	t_lst	*lst;

	lst = app->_srcs;
	while (lst != NULL)
	{
		if (((t_src *) lst->content)->code == code)
			return (((t_src *) lst->content)->_texs->content);
		lst = lst->next;
	}
	return (NULL);
}
