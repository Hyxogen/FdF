/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer_render_line.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 15:27:25 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/20 09:01:22 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../renderer.h"
#include "util/types.h"

void
	_render_line_bresenham(t_image_buffer *buffer,
		t_vector2i left, t_vector2i right, t_color color)
{
	t_int32		dx;
	t_int32		dy;
	t_int32		y_slope;
	t_int32		error;
	t_vector2i	point;

	point = left;
	dx = right.m_x - left.m_x;
	dy = right.m_y - left.m_y;
	error = 0;
	y_slope = 1 + ((dy < 0) * -2);
	dy *= 1 + ((dy < 0) * -2);
	while (point.m_x <= right.m_x)
	{
		ib_put_pixelv(buffer, point, color);
		if (error > 0)
		{
			point.m_y += y_slope;
			error -= 2 * dx;
		}
		error += 2 * dy;
		point.m_x += 1;
	}
}

void
	render_line(t_image_buffer *buffer,
		t_vector2i start, t_vector2i end, t_color color)
{
	if (start.m_x < end.m_x)
		_render_line_bresenham(buffer, start, end, color);
	else
		_render_line_bresenham(buffer, end, start, color);
}
