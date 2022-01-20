/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix4f_mulva.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 15:11:46 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/20 15:18:10 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../matrix4f.h"

void
	matrix4f_mulva(t_vector4f *out, const t_matrix4f *mat,
		const t_vector4f *vec, t_size n)
{
	while (n)
	{
		*out = matrix4f_mulv(mat, vec);
		out++;
		vec++;
		n--;
	}	
}
