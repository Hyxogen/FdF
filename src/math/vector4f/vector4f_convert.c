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
	vector4f_convert3f(t_vector4f *out, t_vector3f *points, t_size n)
{
	while (n)
	{
		*out = *((t_vector4f *) points);
		out->m_w = 0.0f;
		out++;
		points++;
		n--;
	}
}
