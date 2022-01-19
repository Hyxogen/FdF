/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_buffer_create.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 10:05:45 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/19 14:37:08 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../image_buffer.h"

#include "util/mem_utils.h"
#include <stdlib.h>
#include <mlx.h>

t_bool
	_ib_init_values(t_image_buffer *buffer, void *mlx_handle,
		t_int32 width, t_int32 height)
{
	buffer->m_mlx_handle = mlx_handle;
	buffer->m_image_width = width;
	buffer->m_image_height = height;
	return (TRUE);
}

t_bool
	_ib_init_handles(t_image_buffer *buffer)
{
	buffer->m_image_handle = mlx_new_image(
			buffer->m_mlx_handle,
			buffer->m_image_width,
			buffer->m_image_height);
	buffer->m_image_address = (t_byte *) mlx_get_data_addr(
			buffer->m_image_handle,
			&(buffer->m_bit_per_pixel),
			&(buffer->m_line_width),
			&(buffer->m_endian));
	return (buffer->m_image_handle != NULL);
}

t_image_buffer
	*ib_create(void *mlx_handle, t_int32 width, t_int32 height)
{
	t_image_buffer	*buffer;

	buffer = safe_malloc(sizeof(t_image_buffer));
	if (!_ib_init_values(buffer, mlx_handle, width, height)
		|| !_ib_init_handles(buffer))
	{
		free(buffer);
		return (FALSE);
	}
	return (buffer);
}
