/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window_init.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 15:18:43 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/02 08:27:18 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../window.h"
#include <mlx.h>
#include <stddef.h>
#include <stdlib.h>
#include "../../util/mem_utils.h"

t_bool
	_window_mlx_init(t_window *window, void *mlx_handle)
{
	window->m_mlx_handle = mlx_handle;
	window->m_window_handle = mlx_new_window(
			mlx_handle,
			window->m_width,
			window->m_height,
			window->m_title
			);
	return (window->m_window_handle != NULL);
}

t_bool
	_window_init(t_window *window, char *title, t_int32 width, t_int32 height)
{
	window->m_title = title;
	window->m_width = width;
	window->m_height = height;
	window->m_imbuffer_front = NULL;
	return (TRUE);
}

t_window
	*window_create(void *mlx, char *title, t_int32 width, t_int32 height)
{
	t_window	*window;

	window = safe_malloc(sizeof(t_window));
	if (!_window_init(window, title, width, height)
		|| !_window_mlx_init(window, mlx))
	{
		free(window);
		return (NULL);
	}
	return (window);
}
