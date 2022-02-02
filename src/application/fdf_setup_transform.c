/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_setup_transform.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 13:23:57 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/02 14:44:20 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "util/mem_utils.h"
#include <ft_string.h>
#include <ft_stdlib.h>
#include <math.h>

t_matrix4f
	_get_iso_rotation(void)
{
	t_matrix4f	rotinit;
	t_matrix4f	rotxz;
	t_matrix4f	rotzy;
	t_matrix4f	total_rotation;

	rotinit = matrix4f_rotation(vector3f(1.0f, 0.0f, 0.0f), M_PI / 2.0f);
	rotxz = matrix4f_rotation(vector3f(0.0f, 1.0f, 0.0f), M_PI / 4.0f);
	rotzy = matrix4f_rotation(vector3f(1.0f, 0.0f, 0.0f), (7 * M_PI) / 36.0f);
	total_rotation = matrix4f_mulm(&rotzy, &rotxz);
	total_rotation = matrix4f_mulm(&total_rotation, &rotinit);
	return (total_rotation);
}

t_matrix4f
	_get_fit_scale(t_vector4f *vertices, t_int32 count)
{
	t_matrix4f	scale;
	t_fl32		largest;
	t_int32		index;

	if (count > 0)
		largest = vertices->m_x;
	index = 0;
	while (index < count)
	{
		if (ft_fabs(vertices[index].m_x) > largest)
			largest = ft_fabs(vertices[index].m_x);
		if (ft_fabs(vertices[index].m_y) > largest)
			largest = ft_fabs(vertices[index].m_y);
		index++;
	}
	scale = matrix4f_usscale(1.0f / largest);
	scale.m_elements[1 + 1 * 4] *= -1;
	return (scale);
}

t_matrix4f
	_get_iso_translation(const t_map *map)
{
	(void)map;
	return (matrix4f_identity());
}

void
	fdf_setup_transform(t_fdf *instance)
{
	t_matrix4f	flip;
	t_matrix4f	transformation;
	t_vector4f	*vertices;
	t_int32		count;

	count = instance->m_loaded_map->m_width * instance->m_loaded_map->m_height;
	instance->m_map_transform.m_rotation = _get_iso_rotation();
	instance->m_map_transform.m_translation
		= _get_iso_translation(instance->m_loaded_map);
	vertices = safe_malloc(sizeof(t_vector4f) * count);
	flip = matrix4f_sscale(1.0f, -1.0f, -1.0f);
	transformation
		= matrix4f_mulm(&instance->m_map_transform.m_rotation, &flip);
	matrix4f_mulva(vertices, &transformation,
		instance->m_loaded_map->m_vertices, count);
	instance->m_map_transform.m_scale = _get_fit_scale(vertices, count);
}
