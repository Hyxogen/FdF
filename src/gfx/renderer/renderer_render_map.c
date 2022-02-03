/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer_render_map.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 10:24:08 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/03 10:45:01 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../renderer.h"
#include <ft_string.h>
#include <ft_stdlib.h>
#include <stdlib.h>
#include "math/vector2f.h"
#include "util/mem_utils.h"
#include <math.h>

/*Deprecated*/
void
	_clip_coords(t_vector4f *vertices, t_int32 count)
{
	t_fl32	w_comp;
	t_fl32	scale;

	while (count)
	{
		w_comp = vertices->m_w;
		scale = 1.0f;
		if (vertices->m_x < -w_comp)
			*vertices = vector4f_muls(vertices, 1.0f / vertices->m_x);
		if (vertices->m_y < -w_comp)
			*vertices = vector4f_muls(vertices, 1.0f / vertices->m_y);
		if (vertices->m_x > w_comp)
			*vertices = vector4f_muls(vertices, 1.0f / vertices->m_x);
		if (vertices->m_y > w_comp)
			*vertices = vector4f_muls(vertices, 1.0f / vertices->m_y);
		count--;
		vertices++;
	}
}
/*Deprecated*/
void
	_normalize_coords(t_vector4f *vertices, t_int32 count)
{
	t_fl32	w_comp;

	while (count)
	{
		w_comp = vertices->m_w;
		if (w_comp != 1.0f && w_comp != 0.0f)
		{
			vertices->m_x /= w_comp;
			vertices->m_y /= w_comp;
			vertices->m_z /= w_comp;
		}
		vertices->m_w = 1.0f;
		count--;
		vertices++;
	}
}

/*Deprecated*/
void
	_fit_to_unit_cube(t_vector4f *vertices, t_int32 count)
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
	matrix4f_mulvai(&scale, vertices, count);
}

/*Deprecated*/
void
	render_map_fit(t_image_buffer *buffer,
			const t_matrix4f *transformation, const t_map *map, t_color color)
{
	t_vector4f	*vertices;
	t_vector2f	*ndc_vertices;
	t_size		size;	

	size = map->m_width * map->m_height;
	vertices = safe_malloc(sizeof(t_vector4f) * size);
	ndc_vertices = safe_malloc(sizeof(t_vector2f) * size);
	matrix4f_mulva(vertices, transformation, map->m_vertices, size);
	_fit_to_unit_cube(vertices, size);
	vector2f_convert4f(ndc_vertices, vertices, size);
	render_quads_ndc(buffer,
		vector2i(map->m_width, map->m_height), ndc_vertices, color);
	free(vertices);
	free(ndc_vertices);
}

void
	render_map(t_image_buffer *buffer,
			const t_matrix4f *transformation, const t_map *map, t_color color)
{
	t_vector4f	*vertices;
	t_vector2f	*ndc_vertices;
	t_size		size;	

	size = map->m_width * map->m_height;
	vertices = safe_malloc(sizeof(t_vector4f) * size);
	ndc_vertices = safe_malloc(sizeof(t_vector2f) * size);
	matrix4f_mulva(vertices, transformation, map->m_vertices, size);
	vector2f_convert4f(ndc_vertices, vertices, size);
	render_quads(buffer,
		vector2i(map->m_width, map->m_height), vertices, color);
	free(vertices);
	free(ndc_vertices);
}
