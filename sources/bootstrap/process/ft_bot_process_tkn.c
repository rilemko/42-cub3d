/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bot_process_tkn.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:39:29 by mconreau          #+#    #+#             */
/*   Updated: 2023/08/07 14:34:38 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_bot_process_tkn(t_app *app)
{
	ft_tkn_add(app, 1, " ", 0);
	ft_tkn_add(app, 2, "0", ft_color_toint(50, 50, 50));
	ft_tkn_add(app, 3, "1", 0);
	ft_tkn_add(app, 4, "D", ft_color_toint(139, 69, 19));
	ft_tkn_add(app, 6, "P", ft_color_toint(50, 50, 50));
	ft_tkn_add(app, 7, "ENSW", ft_color_toint(255, 0, 0));
}
