/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix4f_persp.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 10:32:23 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/02 10:51:12 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../matrix4f.h"

t_matrix4f
	matrix4f_persp(const t_proj_settings *proj)
{
	t_matrix4f	mat;

	matrix4f_clear(&mat);
	mat.m_elements[0 + 0 * 4]
		= (2.0f * proj->m_near) / (proj->m_right - proj->m_left);
	mat.m_elements[2 + 0 * 4]
		= (proj->m_right + proj->m_left) / (proj->m_right - proj->m_left);
	mat.m_elements[1 + 1 * 4]
		= (2.0f * proj->m_near) / (proj->m_top - proj->m_bottom);
	mat.m_elements[2 + 1 * 4]
		= (proj->m_top + proj->m_bottom) / (proj->m_top - proj->m_bottom);
	mat.m_elements[2 + 2 * 4]
		= -(proj->m_far + proj->m_near) / (proj->m_far - proj->m_near);
	mat.m_elements[3 + 2 * 4]
		= -(2.0f * proj->m_far * proj->m_near) / (proj->m_far - proj->m_near);
	mat.m_elements[2 + 3 * 4] = -1.0f;
	return (mat);
}
