#include "fdf.h"
#include <stdlib.h>

void
	fdf_instance_destroy(t_fdf *instance)
{
	window_destroy(instance->m_main_window, TRUE);
	map_destroy(instance->m_loaded_map);
}

