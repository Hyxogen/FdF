/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 10:00:58 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/02 10:28:01 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "math/vector4f.h"
# include "math/matrix4f.h"
# include <ft_stdbool.h>

typedef struct s_camera {
	t_vector3f	m_position;
	t_vector3f	m_rotation;
	t_matrix4f	m_projection;
}	t_camera;

t_bool		camera_init(t_camera *camera,
				t_vector3f position,
				t_vector3f rotation, t_matrix4f projection);
t_camera	*camera_create(void);
void		camera_destroy(t_camera *camera);

t_matrix4f	camera_get_viewmat(const t_camera *camera);
#endif
