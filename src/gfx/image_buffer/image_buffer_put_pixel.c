/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_buffer_put_pixel.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 12:54:24 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/02 15:22:17 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../image_buffer.h"
#include "util/types.h"
#include <mlx.h>

t_uint32
	ib_encode_color(t_image_buffer *buffer, t_color color)
{
	return (mlx_get_color_value(buffer->m_mlx_handle, color));
}

t_byte
	*ib_get_pixel_address(t_image_buffer *buffer, t_int32 x, t_int32 y)
{
	t_byte	*address;

	address = buffer->m_image_address;
	address += x * (buffer->m_bit_per_pixel >> 3);
	address += y * buffer->m_line_width;
	return (address);
}

void
	ib_put_pixel(t_image_buffer *buffer,
		t_int32 x, t_int32 y, t_color color)
{
	t_int32	*address;

	if (x < 0 || y < 0
		|| x >= buffer->m_image_width || y >= buffer->m_image_height)
		return ;
	address = (t_int32 *) ib_get_pixel_address(buffer, x, y);
	*address = ib_encode_color(buffer, color);
}

void
	ib_put_pixelv(t_image_buffer *buffer,
		t_vector2i point, t_color color)
{
	ib_put_pixel(buffer, point.m_x, point.m_y, color);
}
