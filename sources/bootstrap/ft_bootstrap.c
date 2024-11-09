/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bootstrap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:39:29 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/02 19:36:51 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_bootstrap(t_app *app)
{
	ft_bot_process_err(app);
	ft_bot_process_key(app);
	ft_bot_process_rdr(app);
	ft_bot_process_src(app);
	ft_bot_process_tkn(app);
}
