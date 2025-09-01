/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_err.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:42:35 by mconreau          #+#    #+#             */
/*   Updated: 2023/06/27 23:48:58 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	st_err_clear(void *err)
{
	ft_free((void *) err);
}

void	st_err_initialize(t_err *err)
{
	err->code = 0.00;
	ft_bzero(err->content, MAX_BUFF_SIZE);
}
