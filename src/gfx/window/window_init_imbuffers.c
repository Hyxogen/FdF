/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window_init_imbuffers.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 15:20:07 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/02 15:20:10 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../window.h"
#include "../image_buffer.h"

t_bool
	window_init_imbuffers(t_window *window)
{
	window->m_imbuffer_front
		= ib_create(window->m_mlx_handle, window->m_width, window->m_height);
	return (TRUE);
}
