/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bot_process_err.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:39:29 by mconreau          #+#    #+#             */
/*   Updated: 2023/08/07 15:40:24 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_bot_process_err_next(t_app *app);

void	ft_bot_process_err(t_app *app)
{
	ft_err_add(app, 0.01, "Failed to allocate memory");
	ft_err_add(app, 0.02, "Failed to open file");
	ft_err_add(app, 0.03, "Failed to read file");
	ft_err_add(app, 0.04, "Found empty file");
	ft_err_add(app, 1.01, "Usage: ./cub3d [filename]");
	ft_err_add(app, 1.02, "Failed to load environment");
	ft_err_add(app, 1.03, "Argument #1 (filename) must be in \"*.cub\" format");
	ft_err_add(app, 1.04, "Failed to reload program");
	ft_bot_process_err_next(app);
}

static void	ft_bot_process_err_next(t_app *app)
{
	ft_err_add(app, 2.01, "Found space(s) on emty line");
	ft_err_add(app, 2.02, "Missing texture");
	ft_err_add(app, 2.03, "Unrecognized token");
	ft_err_add(app, 2.04, "Duplicate token");
	ft_err_add(app, 2.05, "Missing argument");
	ft_err_add(app, 2.06, "Too many argument");
	ft_err_add(app, 2.07, "Texture file must be in \"*.png\" format");
	ft_err_add(app, 2.08, "Texture must be on 512px format.");
	ft_err_add(app, 2.09, "Texture colors must have 2 channels");
	ft_err_add(app, 2.10, "Too many channel for the color");
	ft_err_add(app, 2.11, "Color channel must be numeric");
	ft_err_add(app, 2.12, "Color channel must be in range [0-255]");
	ft_err_add(app, 2.13, "Texture tokens must be 0-3 characters");
	ft_err_add(app, 3.01, "Missing map");
	ft_err_add(app, 3.02, "Found empty line");
	ft_err_add(app, 3.03, "Map must be enclosed");
	ft_err_add(app, 3.04, "Missing spawn point");
	ft_err_add(app, 4.01, "MLX : Failed to initialize MLX42");
	ft_err_add(app, 4.02, "MLX : Failed to create texture");
	ft_err_add(app, 4.03, "MLX : Failed to create image");
}
