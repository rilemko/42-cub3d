/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hok_process_262.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:48:47 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/25 15:59:25 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
*	ft_hok_process_262() :
*
*	Hooking process for key 'ARROW RIGHT' (262).
*/
void	ft_hok_process_262(t_app *app, t_bool is_pressed)
{
	if (is_pressed == TRUE)
		ft_game_move_axe(app, +1.00);
}
