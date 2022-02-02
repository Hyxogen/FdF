/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transform_get_matrix.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 13:39:08 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/02 15:00:46 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

t_matrix4f
	transform_get_matrix(const t_transform *transform)
{
	t_matrix4f	transformation;

	transformation
		= matrix4f_mulm(&transform->m_translation, &transform->m_rotation);
	transformation
		= matrix4f_mulm(&transformation, &transform->m_scale);
	return (transformation);
}
