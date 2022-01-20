/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector2i_convert.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 09:58:24 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/20 09:59:49 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../vector2i.h"

void
	vector2i_convert4f(t_vector2i *out,
		const t_vector4f *points, t_size n)
{
	while (n)
	{
		out->m_x = (t_int32) points->m_x;
		out->m_y = (t_int32) points->m_y;
		out++;
		points++;
		n--;
	}
}
