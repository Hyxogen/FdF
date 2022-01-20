/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector3f_inverse.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 16:13:23 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/20 16:14:29 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../vector3f.h"

t_vector3f
	vector3f_inverse(const t_vector3f *vector)
{
	t_vector3f	inverse;

	inverse.m_x = -vector->m_x;
	inverse.m_y = -vector->m_y;
	inverse.m_z = -vector->m_z;
	return (inverse);
}
