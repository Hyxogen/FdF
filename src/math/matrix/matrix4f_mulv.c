/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix4f_mulv.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 12:49:21 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/18 12:49:26 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "matrix4f.h"

t_vector4f
	matri4f_mulv(const t_matrix4f *mat, const t_vector4f *vec)
{
	t_vector4f	mul_vec;
	int			row;

	row = 0;
	while (row < 4)
	{
		mul_vec.u_data.m_elements[row]
			= vector4f_dot(&mat->u_data.m_rows[row], vec);
		row++;
	}
	return (mul_vec);
}
