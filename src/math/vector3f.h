/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector3f.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 12:54:35 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/03 09:22:05 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3F_H
# define VECTOR3F_H

# include "util/types.h"

typedef struct s_vector3f {
	t_fl32	m_x;
	t_fl32	m_y;
	t_fl32	m_z;
}	t_vector3f;

t_vector3f	vector3f(t_fl32 x, t_fl32 y, t_fl32 z);

t_vector3f	vector3f_inverse(const t_vector3f *vector);

t_fl32		vector3f_magnitude(const t_vector3f *vector);

t_vector3f	vector3f_normalize(t_vector3f vector);

t_vector3f	vector3f_zero(void);

t_vector3f	vector3f_muls(const t_vector3f *vector, t_fl32 scalar);
#endif
