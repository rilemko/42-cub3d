/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:24:49 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/24 20:44:29 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_update(t_app *app)
{
	ft_upd_process_hok(app);
	ft_upd_process_mlx(app);
	ft_upd_process_ptr(app);
	ft_upd_process_src(app);
	ft_upd_process_win(app);
}
