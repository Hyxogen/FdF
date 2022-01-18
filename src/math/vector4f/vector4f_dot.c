/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector4f_dot.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 14:58:17 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/18 14:58:40 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../vector4f.h"

float
	vector4f_dot(const t_vector4f *a, const t_vector4f *b)
{
	return (a->m_x * a->m_x + a->m_y * a->m_y
		+ a->m_z * b->m_z + a->m_w * a->m_w);
}
