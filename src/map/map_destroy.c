#include "map.h"
#include <stdlib.h>

void
	map_destroy(t_map *map)
{
	if (map)
		free(map->m_vertices);
	free(map);
}
