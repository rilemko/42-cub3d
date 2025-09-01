/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hok_process_077.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:48:47 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/25 16:45:39 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
*	ft_hok_process_077() :
*
*	Hooking process for key 'M' (077).
*/
void	ft_hok_process_077(t_app *app, t_bool is_pressed)
{
	ft_game_swap_map(app, ft_ternary_dbl(is_pressed == TRUE, +1.00, -1.00));
}
