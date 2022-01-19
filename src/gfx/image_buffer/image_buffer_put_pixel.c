/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_buffer_put_pixel.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 12:54:24 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/19 13:32:04 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../image_buffer.h"
#include "util/types.h"
#include <mlx.h>

t_int32
	ib_encode_color(t_image_buffer *buffer, t_color color)
{
	return (mlx_get_color_value(buffer->m_mlx_handle, color));
}

t_byte
	*ib_get_pixel_address(t_image_buffer *buffer, t_vector2i point)
{
	t_byte	*address;

	address = buffer->m_image_address;
	address += point.m_x * (buffer->m_bit_per_pixel << 3);
	address += point.m_y * buffer->m_line_width;
	return (address);
}

void
	ib_put_pixel(t_image_buffer *buffer,
		t_vector2i point, t_color color)
{
	t_byte	*address;

	address = ib_get_pixel_address(buffer, point);
	*address = ib_encode_color(buffer, color);
}
