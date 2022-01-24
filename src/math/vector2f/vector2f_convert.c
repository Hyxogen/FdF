/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector2f_convert.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 08:25:08 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/24 08:26:26 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../vector2f.h"

void
	vector2f_convert4f(t_vector2f *out, t_vector4f *points, t_size n)
{
	while (n)
	{
		out->m_x = points->m_x;
		out->m_y = points->m_y;
		out++;
		points++;
		n--;
	}
}
