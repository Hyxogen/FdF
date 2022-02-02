/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transform.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 13:20:38 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/02 13:42:35 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

# include "math/matrix4f.h"

typedef struct s_transform {
	t_matrix4f	m_translation;
	t_matrix4f	m_rotation;
	t_matrix4f	m_scale;
}	t_transform;

t_matrix4f	transform_get_matrix(const t_transform *transform);

#endif
