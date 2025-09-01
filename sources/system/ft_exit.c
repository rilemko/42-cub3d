/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:06:22 by mconreau          #+#    #+#             */
/*   Updated: 2023/05/25 22:19:45 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
*	ft_exit() :
*
*	Write { content } to the STDOUT_FILENO stream and exit program
*	with return status { code }.
*/
void	ft_exit(int code, const char *content)
{
	ft_write(STDOUT_FILENO, content);
	exit(code);
}

/*
*	ft_exit_failure() :
*
*	Write { content } to the STDERR_FILENO stream and exit program
*	with return status EXIT_FAILURE (1).
*/
void	ft_exit_failure(const char *content)
{
	ft_write(STDERR_FILENO, content);
	exit(EXIT_FAILURE);
}

/*
*	ft_exit_success() :
*
*	Write { content } to the STDOUT_FILENO stream and exit program
*	with return status EXIT_SUCCESS (0).
*/
void	ft_exit_success(const char *content)
{
	ft_write(STDOUT_FILENO, content);
	exit(EXIT_SUCCESS);
}
