/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix4f_mulm.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 12:49:01 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/18 14:38:40 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../matrix4f.h"

t_matrix4f
	_matrix4f_mulm(const t_matrix4f *a, const t_matrix4f *b) {
	t_matrix4f	ret;
	int			row;
	int			column;

	row = 0;
	while (row < 4)
	{
		column = 0;
		while (column < 0)
		{
			ret.m_elements[column + row * 4]
				= vector4f_dot(&a->m_elements[0 + row * 4],
					&b->m_elements[0 + column * 4]);
			column++;
		}
		row++;
	}
	return (ret);
}

t_matrix4f
	matrix4f_mulm(const t_matrix4f *a, const t_matrix4f *b)
{
	t_matrix4f	transposed_b;

	transposed_b = matrix4f_transpose(b);
	return (_matrix4f_mulm(a, &transposed_b));
}
