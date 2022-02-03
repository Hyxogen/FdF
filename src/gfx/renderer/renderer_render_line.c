/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer_render_line.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 15:27:25 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/03 14:56:11 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../renderer.h"
#include "util/types.h"
#include <ft_stdlib.h>

void
	_render_line_bresenham_lr(t_image_buffer *buffer,
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
	_render_line_bresenham_ud(t_image_buffer *buffer,
		t_vector2i down, t_vector2i up, t_color color)
{
	t_int32		dx;
	t_int32		dy;
	t_int32		x_slope;
	t_int32		error;
	t_vector2i	point;

	point = down;
	dx = up.m_x - down.m_x;
	dy = up.m_y - down.m_y;
	error = 0;
	x_slope = 1 + ((dx < 0) * -2);
	dx *= 1 + ((dx < 0) * -2);
	while (point.m_y <= up.m_y)
	{
		ib_put_pixelv(buffer, point, color);
		if (error > 0)
		{
			point.m_x += x_slope;
			error -= 2 * dy;
		}
		error += 2 * dx;
		point.m_y += 1;
	}
}

void
	render_line_direct(t_image_buffer *buffer,
		t_vector2i start, t_vector2i end, t_color color)
{
	if (ft_abs(end.m_y - start.m_y) < ft_abs(end.m_x - start.m_x))
	{
		if (start.m_x < end.m_x)
			_render_line_bresenham_lr(buffer, start, end, color);
		else
			_render_line_bresenham_lr(buffer, end, start, color);
	}
	else
	{
		if (start.m_y < end.m_y)
			_render_line_bresenham_ud(buffer, start, end, color);
		else
			_render_line_bresenham_ud(buffer, end, start, color);
	}
}

void
	_normalize_vector(t_vector4f *out, const t_vector4f *vecs, t_size count)
{
	while (count)
	{
		if (vecs->m_w != 0.0f)
		{
			out->m_x = vecs->m_x / vecs->m_w;
			out->m_y = vecs->m_y / vecs->m_w;
			out->m_z = vecs->m_z / vecs->m_w;
			out->m_w = 1.0f;
		}
		out++;
		vecs++;
		count--;
	}
}

/*Change clipline if projection near changes*/
void
	render_line(t_image_buffer *buffer,
		t_vector4f start, t_vector4f end, t_color color)
{
	t_vector2f	ndc_start;
	t_vector2f	ndc_end;
	t_vector2i	istart;
	t_vector2i	iend;

	if (!_clip_line(&start, &end, &color))
		return ;
	_normalize_vector(&start, &start, 1);
	_normalize_vector(&end, &end, 1);
	vector2f_convert4f(&ndc_start, &start, 1);
	vector2f_convert4f(&ndc_end, &end, 1);
	_ndc_to_window(buffer, &istart, &ndc_start, 1);
	_ndc_to_window(buffer, &iend, &ndc_end, 1);
	render_line_direct(buffer, istart, iend, color);
}
