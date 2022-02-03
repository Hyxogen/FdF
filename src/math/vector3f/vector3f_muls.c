/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector3f_muls.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 09:19:40 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/03 09:21:23 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../vector3f.h"

t_vector3f
	vector3f_muls(const t_vector3f *vector, t_fl32 scalar)
{
	t_vector3f	result;

	result.m_x = vector->m_x * scalar;
	result.m_y = vector->m_y * scalar;
	result.m_y = vector->m_z * scalar;
	return (result);
}
