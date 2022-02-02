/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_destroy.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 08:29:33 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/02 08:29:33 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdlib.h>

void
	map_destroy(t_map *map)
{
	if (map)
		free(map->m_vertices);
	free(map);
}
