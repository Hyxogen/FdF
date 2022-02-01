#include "fdf.h"
#include "util/mem_utils.h"
#include <stddef.h>

t_fdf	
	*fdf_instance_create()
{
	t_fdf	*instance;

	instance = safe_malloc(sizeof(t_fdf));
	fdf_instance_init(instance, NULL, NULL, NULL);
	return (instance);
}
