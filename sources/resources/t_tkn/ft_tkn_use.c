/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_use.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:18:50 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/02 15:01:32 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_tkn_use(t_app *app, char token)
{
	t_lst	*lst;

	lst = app->_tkns;
	while (lst != NULL)
	{
		if (ft_strpos(((t_tkn *) lst->content)->token, token) != NPOS)
			return (((t_tkn *) lst->content)->code);
		lst = lst->next;
	}
	return (NPOS);
}
