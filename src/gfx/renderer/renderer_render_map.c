#include "../renderer.h"
#include <ft_string.h>
#include <ft_stdlib.h>
#include <stdlib.h>
#include "math/vector2f.h"
#include "util/mem_utils.h"

/*
void
	norm_trans(t_vector4f *vertices, t_int32 count)
{
	t_matrix4f scale;
	t_vector4f *result;
	t_int32	index;
	t_fl32	largest;

	largest = vertices->m_x;
	result = safe_malloc(sizeof(t_vector4f) * count);
	index = 0;
	while (index < count)
	{
		if (ft_abs(vertices[index].m_x) > largest)
			largest = ft_abs(vertices[index].m_x);
		if (ft_abs(vertices[index].m_y) > largest)
			largest = ft_abs(vertices[index].m_y);
		index++;
	}
	scale = matrix4f_usscale(1.0f / largest);
	matrix4f_mulva(result, &scale, vertices, count);
	ft_memcpy(vertices, result, sizeof(t_vector4f) * count);
	free(result);
}*/

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
	_fit_to_unit_cube(vertices, size);
	vector2f_convert4f(ndc_vertices, vertices, size);
	render_quads_ndc(buffer, vector2i(map->m_width, map->m_height), ndc_vertices, color);
	free(vertices);
	free(ndc_vertices);
}

