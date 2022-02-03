/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector4f.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 12:54:35 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/03 11:18:40 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR4F_H
# define VECTOR4F_H

# include "vector3f.h"
# include "../util/types.h"

typedef struct s_vector4f {
	t_fl32	m_x;
	t_fl32	m_y;
	t_fl32	m_z;
	t_fl32	m_w;
}	t_vector4f;

t_vector4f	vector4f_add(const t_vector4f *a, const t_vector4f *b);
t_vector4f	vector4f_subtract(const t_vector4f *a, const t_vector4f *b);

t_vector4f	vector4f_muls(const t_vector4f *a, t_fl32 scalar);

t_fl32		vector4f_dot(const t_vector4f *a, const t_vector4f *b);

void		vector4f_convert3f(t_vector4f *out,
				t_vector3f *points, t_size n, t_fl32 w);
#endif
