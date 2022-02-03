/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_instance_init.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 07:55:58 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/03 15:13:47 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void
	fdf_instance_init(t_fdf *instance,
		void *mlx_handle, t_window *main_window, t_map *loaded_map)
{
	instance->m_mlx_handle = mlx_handle;
	instance->m_main_window = main_window;
	instance->m_loaded_map = loaded_map;
	instance->m_rendermode = rm_ortho;
}
