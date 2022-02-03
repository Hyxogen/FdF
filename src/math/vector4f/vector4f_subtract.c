/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector4f_subtract.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 11:17:31 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/03 11:18:29 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../vector4f.h"

t_vector4f
	vector4f_subtract(const t_vector4f *a, const t_vector4f *b)
{
	t_vector4f	result;

	result.m_x = a->m_x - b->m_x;
	result.m_y = a->m_y - b->m_y;
	result.m_z = a->m_z - b->m_z;
	result.m_w = a->m_w - b->m_w;
	return (result);
}
