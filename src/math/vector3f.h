/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector3f.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 12:54:35 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/18 14:51:54 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3F_H
# define VECTOR3F_H

typedef struct s_vector3f {
	float	m_x;
	float	m_y;
	float	m_z;
}	t_vector3f;

t_vector3f	vector3f_add(const t_vector3f *a, const t_vector3f *b);

t_vector3f	vector3f_muls(const t_vector3f *a, float scalar);

float		vector3f_dot(const t_vector3f *a, const t_vector3f *b);
#endif
