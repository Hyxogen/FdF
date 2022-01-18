/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix4f_ortho.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 12:47:40 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/18 14:31:41 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../matrix4f.h"

t_matrix4f
	matrix4f_ortho(const t_ortho_settings *proj) {
	t_matrix4f	ret;

	matrix4f_clear(&ret);
	ret.m_elements[0 + 0 * 4] = 2.0f / (proj->m_right - proj->m_left);
	ret.m_elements[1 + 1 * 4] = 2.0f / (proj->m_top - proj->m_bottom);
	ret.m_elements[2 + 2 * 4] = 2.0f / (proj->m_far - proj->m_near);
	ret.m_elements[3 + 0 * 4] = -(proj->m_right + proj->m_left)
		/ (proj->m_right - proj->m_left);
	ret.m_elements[3 + 1 * 4] = -(proj->m_top + proj->m_bottom)
		/ (proj->m_top - proj->m_bottom);
	ret.m_elements[3 + 2 * 4] = -(proj->m_far + proj->m_near)
		/ (proj->m_far - proj->m_near);
	ret.m_elements[3 + 3 * 4] = 1.0f;
	return (ret);
}
