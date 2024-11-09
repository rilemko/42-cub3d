/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:18:50 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/03 20:25:48 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_tkn	*ft_tkn_add(t_app *app, int code, const char *token, int color)
{
	t_tkn	*tkn;

	tkn = malloc(sizeof(t_tkn));
	if (tkn != NULL)
	{
		st_tkn_initialize(tkn);
		tkn->code = code;
		ft_strlcpy(tkn->token, token, MAX_CODE_SIZE);
		if (color != 0)
		{
			tkn->is_colored = TRUE;
			tkn->rgb.channel_r = (color >> 24) & 0xFF;
			tkn->rgb.channel_g = (color >> 16) & 0xFF;
			tkn->rgb.channel_b = (color >> 8) & 0xFF;
			tkn->rgb.byte_h = ft_color_byte_h(&tkn->rgb);
			tkn->rgb.byte_l = ft_color_byte_l(&tkn->rgb);
		}
		ft_lstadd_back(&app->_tkns, ft_lstnew((void *) tkn));
	}
	return (tkn);
}
