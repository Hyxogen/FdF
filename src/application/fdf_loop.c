/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_loop.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 07:54:44 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/02 14:45:29 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "map/map.h"
#include "gfx/renderer.h"
#include "math/matrix4f.h"
#include "camera/camera.h"
#include <math.h>

#ifndef M_PI
# define M_PI 3.141592653589793f
#endif

void
	fdf_render_map(t_fdf *instance)
{
	t_matrix4f	transformation;

	ib_clear(instance->m_main_window->m_imbuffer_front);
	transformation = transform_get_matrix(&instance->m_map_transform);
	render_map(instance->m_main_window->m_imbuffer_front,
		&transformation, instance->m_loaded_map, color_white());
	ib_put(instance->m_main_window->m_imbuffer_front,
		instance->m_main_window, vector2i_zero());
}

t_int32
	fdf_loop(void	*instance_ptr)
{
	t_fdf		*instance;

	instance = instance_ptr;
	fdf_render_map(instance);
	return (FALSE);
}
