/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:18:50 by mconreau          #+#    #+#             */
/*   Updated: 2023/06/22 19:52:36 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_err	*ft_err_get(t_app *app, double code)
{
	t_lst	*lst;

	lst = app->_errs;
	while (lst != NULL)
	{
		if (((t_err *) lst->content)->code == code)
			return (lst->content);
		lst = lst->next;
	}
	return (NULL);
}
