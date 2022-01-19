/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer_render_line.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 15:27:25 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/19 15:35:05 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../renderer.h"
#include "util/types.h"

void
	_render_line(t_image_buffer *buffer, t_vector2i left, t_vector2i right)
{
	t_int32		dx;
	t_int32		dy;
	t_int32		y_inv;
	t_vector2i	point;

	dx = end.m_x - start.m_x;
	dy = end.m_y - start.m_y;
	y_inv = 1;
	if (dy < 0)
	{
		dy = -dy;
		y_inv = -y_inv;
	}
	while (point.m_x < right.m_x)
	{
		
	}
}

void
	render_line(t_image_buffer *buffer, t_vector2i start, t_vector2i end)
{
	
}
