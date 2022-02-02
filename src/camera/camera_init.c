/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera_init.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 10:06:14 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/02 10:07:34 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_bool
	camera_init(t_camera *camera,
		t_vector3f position, t_vector3f rotation, t_matrix4f projection)
{
	camera->m_position = position;
	camera->m_rotation = rotation;
	camera->m_projection = projection;
	return (TRUE);
}
