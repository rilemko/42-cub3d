/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:18:50 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/02 15:25:06 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_key	*ft_key_get(t_app *app, int code)
{
	t_lst	*lst;

	lst = app->_keys;
	while (lst != NULL)
	{
		if (((t_key *) lst->content)->code == code)
			return (lst->content);
		lst = lst->next;
	}
	return (NULL);
}
