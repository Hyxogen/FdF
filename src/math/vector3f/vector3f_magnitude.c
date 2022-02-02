/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector3f_magnitude.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 08:03:10 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/02 15:06:01 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "platform.h"
#include "../vector3f.h"
#include <math.h>

t_fl32
	vector3f_magnitude(const t_vector3f *vector)
{
	return (sqrtf(
			(vector->m_x * vector->m_x)
			+ (vector->m_y * vector->m_y)
			+ (vector->m_z * vector->m_z)));
}
