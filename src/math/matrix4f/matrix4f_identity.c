/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix4f_identity.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 15:59:44 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/20 16:01:46 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../matrix4f.h"

void	
	matrix4f_make_identiy(t_matrix4f *mat)
{
	matrix4f_clear(mat);
	mat->m_elements[0 + 0 * 4] = 1.0f;
	mat->m_elements[1 + 1 * 4] = 1.0f;
	mat->m_elements[2 + 2 * 4] = 1.0f;
	mat->m_elements[3 + 3 * 4] = 1.0f;
}

t_matrix4f	matrix4f_identity(void)
{
	t_matrix4f	identity_matrix;

	matrix4f_make_identiy(&identity_matrix);
	return (identity_matrix);
}
