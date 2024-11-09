/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_use.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:18:50 by mconreau          #+#    #+#             */
/*   Updated: 2023/08/07 15:01:32 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_err_use(t_app *app, double code)
{
	t_err	*err;

	err = ft_err_get(app, code);
	if (err != NULL)
		return (err->content);
	return ("An error has occurred");
}
