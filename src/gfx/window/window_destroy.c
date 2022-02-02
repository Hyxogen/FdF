/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window_destroy.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 15:20:31 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/02 08:27:40 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../window.h"
#include "../image_buffer.h"
#include <mlx.h>
#include <stdlib.h>

void
	_window_destroy_mlx(t_window *window)
{
	mlx_clear_window(window->m_mlx_handle, window->m_window_handle);
	mlx_destroy_window(window->m_mlx_handle, window->m_window_handle);
}

void
	_window_destroy_imbuffers(t_window *window)
{
	if (window->m_imbuffer_front)
		mlx_destroy_image(window->m_mlx_handle,
			window->m_imbuffer_front->m_image_handle);
}

void
	window_destroy(t_window *window, t_bool free_self)
{
	_window_destroy_imbuffers(window);
	_window_destroy_mlx(window);
	if (free_self)
		free(window);
}
