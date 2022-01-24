/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector3f_normalize.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 08:01:01 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/24 08:02:56 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../vector3f.h"

t_vector3f
	vector3f_normalize(t_vector3f vector)
{
	t_fl32	magnitude;

	magnitude = vector3f_magnitude(&vector);
	if (magnitude == 0)
		return (vector);
	vector.m_x /= magnitude;
	vector.m_y /= magnitude;
	vector.m_z /= magnitude;
	return (vector);
}
