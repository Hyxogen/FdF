/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix4f_mulv.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 12:49:21 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/18 14:52:36 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../matrix4f.h"

t_vector4f
	matri4f_mulv(const t_matrix4f *mat, const t_vector4f *vec)
{
	t_vector4f	mul_vec;
	float		*mul_elements;
	int			row;

	row = 0;
	while (row < 4)
	{
		mul_elements = (float *) &mul_vec;
		mul_elements[row]
			= vector4f_dot((t_vector4f *) &mat->m_elements[0 + row * 4], vec);
		row++;
	}
	return (mul_vec);
}
