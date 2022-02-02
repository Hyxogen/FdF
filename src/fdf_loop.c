/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_loop.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 07:54:44 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/02 07:54:44 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "map/map.h"
#include "gfx/renderer.h"
#include "math/matrix4f.h"
#include <math.h>

#ifndef M_PI
# define M_PI 3.141592653589793f
#endif

void
	fdf_loop_iso(t_fdf *instance)
{
	t_matrix4f	rotinit;
	t_matrix4f	rotxz;
	t_matrix4f	rotzy;
	t_matrix4f	flip;
	t_matrix4f	transformation;

	ib_clear(instance->m_main_window->m_imbuffer_front);
	rotinit = matrix4f_rotation(vector3f(1.0f, 0.0f, 0.0f), M_PI / 2.0f);
	rotxz = matrix4f_rotation(vector3f(0.0f, 1.0f, 0.0f), M_PI / 4.0f);
	rotzy = matrix4f_rotation(vector3f(1.0f, 0.0f, 0.0f), (7 * M_PI) / 36.0f);
	flip = matrix4f_sscale(1.0f, -1.0f, 1.0f);
	transformation = matrix4f_mulm(&rotzy, &rotxz);
	transformation = matrix4f_mulm(&transformation, &rotinit);
	transformation = matrix4f_mulm(&transformation, &flip);
	render_map(instance->m_main_window->m_imbuffer_front,
		&transformation, instance->m_loaded_map, color_white());
	ib_put(instance->m_main_window->m_imbuffer_front,
		instance->m_main_window, vector2i_zero());
}

void
	fdf_loop_pers(t_fdf *instance)
{
	(void)instance;
}

void
	fdf_loop_ortho(t_fdf *instance)
{
	(void)instance;
}

t_int32
	fdf_loop(void	*instance_ptr)
{
	t_fdf		*instance;

	instance = instance_ptr;
	if (instance->m_render_mode == rm_iso)
		fdf_loop_iso(instance);
	else if (instance->m_render_mode == rm_pers)
		fdf_loop_pers(instance);
	else
		fdf_loop_ortho(instance);
	return (FALSE);
}
