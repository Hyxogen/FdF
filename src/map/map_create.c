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

t_map
	*map_create(t_int32 width, t_int32 height, t_vector3f *vertices)
{
	t_map	*map;

	map = safe_malloc(sizeof(t_map));
	map_init(map, width, height, vertices);
	return (map);
}
