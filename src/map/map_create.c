/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_create.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 09:09:10 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/20 09:10:41 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "util/mem_utils.h"

t_vector3f
	*_map_convert_heights(t_int32 width, t_int32 height, t_int32 *heights, t_int32 spacing)
{
	t_vector3f	*vertices;
	t_int32		index;
	t_int32		x;
	t_int32		y;

	vertices = safe_malloc(sizeof(t_vector3f) * width * height);
	index = 0;
	x = (width / 2) * -spacing;
	y = (height / 2) * -spacing;
	while (index < width * height)
	{
		vertices[index].m_x = x;
		vertices[index].m_y = y;
		vertices[index].m_z = (float) heights[index];
		index++;
		x += spacing;
		if ((index % width) == 0)
		{
			x = (width / 2) * -spacing;
			y += spacing;
		}
	}
	return (vertices);
}

t_map
	*map_create(t_int32 width, t_int32 height, t_int32 *heights)
{
	t_vector3f	*vertices;
	t_map		*map;

	vertices = _map_convert_heights(width, height, heights, 50);
	map = safe_malloc(sizeof(t_map));
	map_init(map, width, height, vertices);
	return (map);
}
