/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:41:42 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/25 16:42:01 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_hook(t_m_key input, void *app)
{
	t_key	*key;

	key = ft_key_get((t_app *) app, input.key);
	if (key != NULL)
	{
		if (input.action == MLX_PRESS)
		{
			key->is_pressed = TRUE;
			return ((void)((t_app *) app)->hok.count++);
		}
		if (input.action == MLX_RELEASE)
		{
			key->callback(app, FALSE);
			key->is_pressed = FALSE;
			return ((void)((t_app *) app)->hok.count--);
		}
	}
}
