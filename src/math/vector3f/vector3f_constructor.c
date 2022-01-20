/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector3f_constructor.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 15:07:50 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/20 15:19:04 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../vector3f.h"

t_vector3f
	vector3f(float x, float y, float z)
{
	t_vector3f	vector;

	vector.m_x = x;
	vector.m_y = y;
	vector.m_z = z;
	return (vector);
}
