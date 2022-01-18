/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix4f_mulm.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 12:49:01 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/18 12:52:52 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "matrix4f.h"

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
			ret.u_data.m_elements[column + row * 4]
				= vector4f_dot(&a->u_data.m_rows[row],
					&b->u_data.m_rows[column]);
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
