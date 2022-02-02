/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera_create.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 10:04:52 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/02 10:30:04 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "util/mem_utils.h"

t_camera
	*camera_create(void)
{
	t_camera	*camera;

	camera = safe_malloc(sizeof(t_camera));
	camera_init(camera, vector3f_zero(), vector3f_zero(), matrix4f_identity());
	return (camera);
}
