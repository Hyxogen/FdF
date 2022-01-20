/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 09:10:48 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/20 14:56:19 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "mem_utils.h"

t_bool
	_map_set_sizes(t_map *map,
		t_int32 width, t_int32 height)
{
	map->m_width = width;
	map->m_height = height;
	return (TRUE);
}

t_bool
	_map_set_vertices(t_map *map,
		t_int32 width, t_int32 height, t_vector4f *vertices)
{
	map->m_vertices = vertices;
}

t_bool
	map_set_vertices(t_map *map,
		t_int32 width, t_int32 height, t_vector3f *vertices)
{
	t_vector4f	*vec4_vertices;

	vec4_vertices = safe_malloc(sizeof(t_vector4f) * width * height);
	vector4f_convert3f(vec4_vertices, vertices, width * height);
	_map_set_vertices(map, width, height, vec4_vertices);
}

t_bool
	map_init(t_map *map,
			t_int32 width, t_int32 height, t_vector3f *vertices)
{
	_map_set_sizes(map, width, height);
	map_set_vertices(map, width, height, vertices);
}
