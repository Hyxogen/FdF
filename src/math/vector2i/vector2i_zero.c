/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector2i_zero.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 08:40:05 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/20 08:40:50 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../vector2i.h"

t_vector2i
	vector2i_zero(void)
{
	t_vector2i	zero;

	zero.m_x = 0;
	zero.m_y = 0;
	return (zero);
}
