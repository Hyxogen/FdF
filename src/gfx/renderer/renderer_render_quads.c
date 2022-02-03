/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer_render_quads.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 09:42:09 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/20 12:51:08 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../renderer.h"

/*TODO pass from and to by pointer*/
void
	_render_quads_part(t_image_buffer *buffer,
		t_vector4f from, t_vector4f to, t_color color)
{
	render_line(buffer, from, to, color);
}

void
	render_quads(t_image_buffer *buffer,
		t_vector2i dimensions, const t_vector4f *points, t_color color)
{
	t_int32		x;
	t_int32		y;

	y = 0;
	while (y < dimensions.m_y)
	{
		x = 0;
		while (x < dimensions.m_x)
		{
			if ((x + 1) < dimensions.m_x)
				_render_quads_part(buffer,
					points[(x + 0) + (y + 0) * dimensions.m_x],
					points[(x + 1) + (y + 0) * dimensions.m_x],
					color);
			if ((y + 1) < dimensions.m_y)
				_render_quads_part(buffer,
					points[(x + 0) + (y + 0) * dimensions.m_x],
					points[(x + 0) + (y + 1) * dimensions.m_x],
					color);
			x++;
		}
		y++;
	}	
}
