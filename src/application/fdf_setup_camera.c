/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_setup_camera.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 10:13:58 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/02 12:40:23 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void
	_fdf_setup_camera_default_projection(t_fdf *instance)
{
	t_proj_settings	persp_settings;

	persp_settings.m_near = -1.0f;
	persp_settings.m_far = 1.0f;
	persp_settings.m_left = -6.0f;
	persp_settings.m_right = 6.0f;
	persp_settings.m_top = 6.0f;
	persp_settings.m_bottom = -6.0f;
	instance->m_camera->m_projection = matrix4f_persp(&persp_settings);
}

t_bool
	fdf_setup_camera(t_fdf *instance)
{
	instance->m_camera = camera_create();
	instance->m_camera->m_position.m_z = 0.04f;
	_fdf_setup_camera_default_projection(instance);
	return (TRUE);
}
