/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector4f_add.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 14:53:39 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/03 14:25:56 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../vector4f.h"

t_vector4f
	vector4f_add(const t_vector4f *a, const t_vector4f *b)
{
	t_vector4f	ret;

	ret.m_x = a->m_x + b->m_x;
	ret.m_y = a->m_y + b->m_y;
	ret.m_z = a->m_z + b->m_z;
	ret.m_w = a->m_w + b->m_w;
	return (ret);
}
