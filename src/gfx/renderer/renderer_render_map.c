/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer_render_map.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 10:24:08 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/03 14:56:42 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../renderer.h"
#include <ft_string.h>
#include <ft_stdlib.h>
#include <stdlib.h>
#include "math/vector2f.h"
#include "util/mem_utils.h"
#include <math.h>

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
