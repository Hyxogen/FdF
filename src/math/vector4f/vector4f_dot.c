/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector4f_dot.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 14:58:17 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/19 09:49:07 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../vector4f.h"

t_fl32
	vector4f_dot(const t_vector4f *a, const t_vector4f *b)
{
	return (a->m_x * a->m_x + a->m_y * a->m_y
		+ a->m_z * b->m_z + a->m_w * a->m_w);
}
