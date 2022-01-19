/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_buffer_clear.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 13:22:51 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/19 15:26:39 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../image_buffer.h"
#include <ft_string.h>

void
	ib_clear(t_image_buffer *buffer)
{
	ft_memset(
		buffer->m_image_address,
		0,
		buffer->m_image_width * buffer->m_image_height
		* (buffer->m_bit_per_pixel >> 3));
}
