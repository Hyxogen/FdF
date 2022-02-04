/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer_clipping.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 09:48:36 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/04 08:12:33 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../renderer.h"

t_bool
	_should_clip(const t_vector4f *vector)
{
	return (vector->m_x < -vector->m_w || vector->m_x > vector->m_w
		|| vector->m_y < -vector->m_w || vector->m_y > vector->m_w
		|| vector->m_z < -vector->m_w || vector->m_z > vector->m_w);
}

void
	_clip_line_part(t_vector4f *visible, t_vector4f *clipped,
		t_fl32 sign, t_int32 axis)
{
	t_fl32	*clip_ele;
	t_fl32	*visb_ele;
	t_fl32	scale;

	clip_ele = (t_fl32 *) clipped;
	visb_ele = (t_fl32 *) visible;
	if (clip_ele[axis] * sign <= clip_ele[3])
		return ;
	scale = visb_ele[3] - visb_ele[axis] * sign;
	scale = scale / (scale - (clip_ele[3] - clip_ele[axis] * sign));
	*clipped = vector4f_subtract(clipped, visible);
	*clipped = vector4f_muls(clipped, scale);
	*clipped = vector4f_add(clipped, visible);
}

t_bool
	_clip_line(t_vector4f *start, t_vector4f *end)
{
	if (_should_clip(start) && _should_clip(end))
		return (FALSE);
	if (_should_clip(start))
	{
		_clip_line_part(end, start, 1, 0);
		_clip_line_part(end, start, -1, 0);
		_clip_line_part(end, start, 1, 1);
		_clip_line_part(end, start, -1, 1);
		return (TRUE);
	}
	_clip_line_part(start, end, 1, 0);
	_clip_line_part(start, end, -1, 0);
	_clip_line_part(start, end, 1, 1);
	_clip_line_part(start, end, -1, 1);
	return (TRUE);
}
