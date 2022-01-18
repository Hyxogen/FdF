/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector4f.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 12:54:35 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/18 12:54:54 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR4F_H
# define VERCTOR4F_H

typedef struct s_vector4f {
	union {
		struct {
			float	m_x;
			float	m_y;
			float	m_z;
			float	m_w;
		} s_coords;
		float	m_elements[4];
	} u_data;
}	t_vector4f;

t_vector4f	vector4f_add(const t_vector4f *a, const t_vector4f *b);

t_vector4f	vector4f_muls(const t_vector4f *a, float scalar);

float		vector4f_dot(const t_vector4f *a, const t_vector4f *b);
#endif
