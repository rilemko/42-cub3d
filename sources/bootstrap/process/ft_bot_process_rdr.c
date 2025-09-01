/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bot_process_rdr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:39:29 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/03 16:40:04 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_bot_process_rdr(t_app *app)
{
	ft_lstadd_back(&app->_rdrs, ft_lstnew(ft_render_00));
	ft_lstadd_back(&app->_rdrs, ft_lstnew(ft_render_01));
	ft_lstadd_back(&app->_rdrs, ft_lstnew(ft_render_02));
}
