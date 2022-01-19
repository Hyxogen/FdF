/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_buffer_put.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 13:21:24 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/19 13:32:28 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../image_buffer.h"
#include <mlx.h>

t_bool
	ib_put(t_image_buffer *buffer,
		t_window *window, t_vector2i point)
{
	mlx_put_image_to_window(
		buffer->m_mlx_handle,
		window->m_window_handle,
		buffer->m_image_handle,
		point.m_x,
		point.m_y);
	return (TRUE);
}
