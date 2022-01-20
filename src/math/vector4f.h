/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector4f.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 12:54:35 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/20 09:18:29 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR4F_H
# define VECTOR4F_H

# include "../util/types.h"

typedef struct s_vector4f {
	t_fl32	m_x;
	t_fl32	m_y;
	t_fl32	m_z;
	t_fl32	m_w;
}	t_vector4f;

t_vector4f	vector4f_add(const t_vector4f *a, const t_vector4f *b);

t_vector4f	vector4f_muls(const t_vector4f *a, t_fl32 scalar);

t_fl32		vector4f_dot(const t_vector4f *a, const t_vector4f *b);

void		vector4f_convert3f(t_vector4f *out, t_vector3f *points, size_t n);
#endif
