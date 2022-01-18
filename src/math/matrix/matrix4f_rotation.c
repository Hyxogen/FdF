/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix4f_rotation.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 12:55:39 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/18 14:39:15 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../matrix4f.h"
#include <math.h>
#include <ft_string.h>

t_matrix4f
	_matrix4f_rotation(const t_vector3f *axis, float s, float c, float omc)
{
	t_matrix4f	out;

	ft_memset(&out, 0, sizeof(t_matrix4f));
	return (out);
}

t_matrix4f
	matrix4f_rotation(const t_vector3f *axis, float angle)
{
	float		s;
	float		c;
	float		omc;

	s = sin(angle);
	c = cos(angle);
	omc = 1.0f - c;
}
