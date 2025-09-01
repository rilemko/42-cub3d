/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bot_process_key.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:39:29 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/25 16:28:12 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_bot_process_key(t_app *app)
{
	ft_key_add(app, KEY_A, &ft_hok_process_065);
	ft_key_add(app, KEY_D, &ft_hok_process_068);
	ft_key_add(app, KEY_E, &ft_hok_process_069);
	ft_key_add(app, KEY_M, &ft_hok_process_077);
	ft_key_add(app, KEY_R, &ft_hok_process_082);
	ft_key_add(app, KEY_S, &ft_hok_process_083);
	ft_key_add(app, KEY_W, &ft_hok_process_087);
	ft_key_add(app, KEY_ESCAPES, &ft_hok_process_256);
	ft_key_add(app, KEY_ARROW_R, &ft_hok_process_262);
	ft_key_add(app, KEY_ARROW_L, &ft_hok_process_263);
}
