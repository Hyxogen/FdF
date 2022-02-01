/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector3f_convert.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 09:30:53 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/20 09:37:53 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../vector4f.h"

void
	vector4f_convert3f(t_vector4f *out, t_vector3f *points, t_size n, t_fl32 w)
{
	while (n)
	{
		out->m_x = points->m_x;
		out->m_y = points->m_y;
		out->m_z = points->m_z;
		out->m_w = w;
		out++;
		points++;
		n--;
	}
}
