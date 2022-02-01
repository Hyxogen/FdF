/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix4f.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 12:50:59 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/20 15:58:36 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX4F_H
# define MATRIX4F_H

# include "vector4f.h"
# include "vector3f.h"

typedef struct s_matrix4f {
	t_fl32	m_elements[4 * 4];
}	t_matrix4f;

typedef struct s_ortho_settings {
	t_fl32	m_near;
	t_fl32	m_far;
	t_fl32	m_left;
	t_fl32	m_right;
	t_fl32	m_top;
	t_fl32	m_bottom;
}	t_ortho_settings;

void		matrix4f_clear(t_matrix4f *mat);

t_matrix4f	matrix4f_mulm(const t_matrix4f *a, const t_matrix4f *b);

t_vector4f	matrix4f_mulv(const t_matrix4f *mat, const t_vector4f *vec);

void		matrix4f_mulva(t_vector4f *out, const t_matrix4f *mat,
				const t_vector4f *vec, t_size n);
void		matrix4f_mulvai(const t_matrix4f *mat, t_vector4f *vec,
				t_size n);

t_matrix4f	matrix4f_ortho(const t_ortho_settings *proj);

t_matrix4f	matrix4f_transpose(const t_matrix4f *mat);

void		matrix4f_make_identiy(t_matrix4f *mat);
t_matrix4f	matrix4f_identity(void);
t_matrix4f	matrix4f_rotation(t_vector3f axis, t_fl32 angle);
t_matrix4f	matrix4f_translation(t_vector3f vec);
t_matrix4f	matrix4f_sscale(t_fl32 x, t_fl32 y, t_fl32 z);
t_matrix4f	matrix4f_vscale(t_vector3f scale);
t_matrix4f	matrix4f_usscale(t_fl32 scalar);

#endif
