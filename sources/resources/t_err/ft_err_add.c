/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:18:50 by mconreau          #+#    #+#             */
/*   Updated: 2023/06/23 21:30:06 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_err	*ft_err_add(t_app *app, double code, const char *content)
{
	t_err	*err;

	err = malloc(sizeof(t_err));
	if (err != NULL)
	{
		st_err_initialize(err);
		err->code = code;
		ft_strlcpy(err->content, content, MAX_BUFF_SIZE);
		ft_lstadd_back(&app->_errs, ft_lstnew((void *) err));
	}
	return (err);
}
