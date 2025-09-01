/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hypot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:04:59 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/19 00:48:46 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_hypot(double xa, double ya, double xb, double yb)
{
	return (sqrt((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya)));
}
