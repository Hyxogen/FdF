/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix4f_translation.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 15:57:09 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/20 15:59:36 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../matrix4f.h"

t_matrix4f
	matrix4f_translation(t_vector3f vec)
{
	t_matrix4f	translation_mat;

	matrix4f_make_identiy(&translation_mat);
	translation_mat.m_elements[3 + 0 * 4] = vec.m_x;
	translation_mat.m_elements[3 + 1 * 4] = vec.m_y;
	translation_mat.m_elements[3 + 2 * 4] = vec.m_z;
	return (translation_mat);
}
