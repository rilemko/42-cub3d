/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:18:50 by mconreau          #+#    #+#             */
/*   Updated: 2023/06/28 01:20:51 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_tkn	*ft_tkn_get(t_app *app, char token)
{
	t_lst	*lst;

	lst = app->_tkns;
	while (lst != NULL)
	{
		if (ft_strpos(((t_tkn *) lst->content)->token, token) != NPOS)
			return (lst->content);
		lst = lst->next;
	}
	return (NULL);
}
