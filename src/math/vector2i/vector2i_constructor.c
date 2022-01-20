/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector2i_constructor.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 10:05:07 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/20 10:05:54 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../vector2i.h"

t_vector2i
	vector2i(t_int32 x, t_int32 y)
{
	t_vector2i	vector;

	vector.m_x = x;
	vector.m_y = y;
	return (vector);
}
