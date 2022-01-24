/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer_render_quads_ndc.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 08:17:23 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/24 08:43:01 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../renderer.h"

void
	_ndc_to_window(t_image_buffer *buffer,
		t_vector2i *out, t_vector2f *ndc_points, t_size n)
{
	while (n)
	{
		out->m_x = (t_int32)((ndc_points->m_x + 1) * ((t_fl32) buffer->m_image_width / 2));
		out->m_y = (t_int32)((ndc_points->m_y + 1) * ((t_fl32) buffer->m_image_height / 2));
		out++;
		ndc_points++;
		n--;
	}
}

void
	_render_quads_ndc_part(t_image_buffer *buffer,
			t_vector2f from, t_vector2f to, t_color color)
{
	t_vector2i	i_from;
	t_vector2i	i_to;

	_ndc_to_window(buffer, &i_from, &from, 1);
	_ndc_to_window(buffer, &i_to, &to, 1);
	render_line(buffer, i_from, i_to, color);
}

void
	render_quads_ndc(t_image_buffer *buffer,
			t_vector2i dimensions, const t_vector2f *ndc_points, t_color color)
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
				_render_quads_ndc_part(buffer,
					ndc_points[(x + 0) + (y + 0) * dimensions.m_x],
					ndc_points[(x + 1) + (y + 0) * dimensions.m_x],
					color);
			if ((y + 1) < dimensions.m_y)
				_render_quads_ndc_part(buffer,
					ndc_points[(x + 0) + (y + 0) * dimensions.m_x],
					ndc_points[(x + 0) + (y + 1) * dimensions.m_x],
					color);
			x++;
		}
		y++;
	}	
}
