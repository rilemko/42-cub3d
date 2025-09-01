/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bot_process_src.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:39:29 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/24 17:58:03 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_bot_process_src(t_app *app)
{
	ft_src_add(app, 1, "C ", &ft_prs_process_clr);
	ft_src_add(app, 2, "F ", &ft_prs_process_clr);
	ft_src_add(app, 3, "D ", &ft_prs_process_tex);
	ft_src_add(app, 4, "EA", &ft_prs_process_tex);
	ft_src_add(app, 5, "P ", &ft_prs_process_tex);
	ft_src_add(app, 6, "SO", &ft_prs_process_tex);
	ft_src_add(app, 7, "NO", &ft_prs_process_tex);
	ft_src_add(app, 8, "WE", &ft_prs_process_tex);
}
