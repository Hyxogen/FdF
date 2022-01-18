/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix4f_transpose.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 12:43:48 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/18 12:47:08 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "matrix4f.h"

t_matrix4f
	matrix4f_transpose(const t_matrix4f *mat)
{
	t_matrix4f	transposed_mat;
	int			column;
	int			row;

	row = 0;
	while (row < 4)
	{
		column = 0;
		while (column < 4)
		{
			transposed_mat.u_data.m_elements[column + row * 4]
				= mat->u_data.m_elements[row + column * 4];
			column++;
		}
		row++;
	}
	return (transposed_mat);
}
