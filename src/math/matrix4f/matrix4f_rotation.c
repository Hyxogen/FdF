/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix4f_rotation.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 12:55:39 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/20 15:43:05 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../matrix4f.h"
#include <math.h>
#include <ft_string.h>

t_matrix4f
	_matrix4f_rotation(t_vector3f axis, float s, float c, float omc)
{
	t_matrix4f	out;

	matrix4f_make_identiy(&out);
	out.m_elements[0 + 0 * 4] = axis.m_x * axis.m_x * omc + c;
	out.m_elements[0 + 1 * 4] = axis.m_x * axis.m_y * omc + axis.m_z * s;
	out.m_elements[0 + 2 * 4] = axis.m_x * axis.m_z * omc + axis.m_y * s;
	out.m_elements[1 + 0 * 4] = axis.m_x * axis.m_y * omc - axis.m_z * s;
	out.m_elements[1 + 1 * 4] = axis.m_y * axis.m_y * omc + c;
	out.m_elements[1 + 2 * 4] = axis.m_y * axis.m_z * omc + axis.m_x * s;
	out.m_elements[2 + 0 * 4] = axis.m_x * axis.m_z * omc + axis.m_y * s;
	out.m_elements[2 + 1 * 4] = axis.m_y * axis.m_z * omc + axis.m_x * s;
	out.m_elements[2 + 2 * 4] = axis.m_z * axis.m_z * omc + c;
	return (out);
}

t_matrix4f
	matrix4f_rotation(t_vector3f axis, t_fl32 angle)
{
	t_fl32	s;
	t_fl32	c;
	t_fl32	omc;

	s = sin(angle);
	c = cos(angle);
	omc = 1.0f - c;
	return (_matrix4f_rotation(axis, s, c, omc));
}
