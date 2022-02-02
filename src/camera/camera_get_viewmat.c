/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera_get_viewmat.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 10:08:20 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/02 12:35:20 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*Setting up rotation matrix might be a bit more difficult*/

#include "camera.h"

t_matrix4f
	camera_get_viewmat(const t_camera *camera)
{
	t_matrix4f	translation;
	t_matrix4f	rotation;

	translation = matrix4f_translation(camera->m_position);
	rotation = matrix4f_rotation(
			vector3f(0.0f, 1.0f, 0.0f), camera->m_rotation.m_y);
	return (matrix4f_mulm(&rotation, &translation));
}
