/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector4f_muls.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 14:57:51 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/18 14:58:08 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../vector4f.h"

t_vector4f
	vector4f_muls(const t_vector4f *a, float scalar)
{
	t_vector4f	ret;

	ret = *a;
	ret.m_x *= scalar;
	ret.m_y *= scalar;
	ret.m_w *= scalar;
	ret.m_z *= scalar;
	return (ret);
}
