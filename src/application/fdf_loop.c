/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_loop.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 07:54:44 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/03 16:22:26 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "map/map.h"
#include "gfx/renderer.h"
#include "math/matrix4f.h"

t_proj_settings
	get_projection_settings(void)
{
	t_proj_settings	settings;

	settings.m_near = 1.0f;
	settings.m_far = 100.0f;
	settings.m_left = 1.0f;
	settings.m_right = -1.0f;
	settings.m_top = -1.0f;
	settings.m_bottom = 1.0f;
	return (settings);
}

t_matrix4f
	get_persp_mat(void)
{
	t_proj_settings	settings;
	t_matrix4f		persp_matrix;

	settings = get_projection_settings();
	persp_matrix = matrix4f_persp(&settings);
	return (persp_matrix);
}

t_matrix4f
	get_ortho_mat(void)
{
	t_proj_settings	settings;
	t_matrix4f		ortho_matrix;

	settings = get_projection_settings();
	ortho_matrix = matrix4f_ortho(&settings);
	return (ortho_matrix);
}

void
	fdf_render_map(t_fdf *instance)
{
	t_matrix4f	projection;
	t_matrix4f	transformation;

	ib_clear(instance->m_main_window->m_imbuffer_front);
	transformation = transform_get_matrix(&instance->m_map_transform);
	if (instance->m_rendermode == rm_ortho)
		projection = get_ortho_mat();
	else
		projection = get_persp_mat();
	transformation = matrix4f_mulm(&projection, &transformation);
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
