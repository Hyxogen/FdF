/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector3f_zero.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 10:28:36 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/02 10:29:32 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../vector3f.h"

t_vector3f
	vector3f_zero(void)
{
	t_vector3f	zero_vec;

	zero_vec.m_x = 0.0f;
	zero_vec.m_y = 0.0f;
	zero_vec.m_z = 0.0f;
	return (zero_vec);
}
