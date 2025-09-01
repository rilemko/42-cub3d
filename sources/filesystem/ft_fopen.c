/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fopen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:51:56 by mconreau          #+#    #+#             */
/*   Updated: 2023/05/25 22:32:51 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_rt	ft_fopen(const char *filename, t_fd *file_descriptor, const char *mode)
{
	int	flags;

	flags = 0;
	flags |= ft_ternary_int(ft_strpos(mode, 'r') != -1, O_RDONLY, 0);
	flags |= ft_ternary_int(ft_strpos(mode, 'w') != -1, O_CREAT | O_WRONLY, 0);
	return (ft_open(filename, file_descriptor, flags));
}
