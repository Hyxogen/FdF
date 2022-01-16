#ifndef MATRIX4F_H
# define MATRIX4F_H

# include "vector4f.h"

typedef struct s_matrix4f {
	union {
		float m_elements[4 * 4];
		t_vector4f m_rows;
	} u_data;
}	t_matrix4f;

typedef struct s_ortho_settings {
	float m_near;
	float m_far;
	float m_left;
	float m_right;
	float m_top;
	float m_bottom;
}	t_ortho_settings;

t_matrix4f matrix4f_mulm(const t_matrix4f *a, const t_matrix4f *b);

t_vector4f matri4f_mulv(const t_matrix4f *mat, const t_vector4f *vec);

t_matrix4f matrix4f_ortho(const t_ortho_settings *proj);

#endif
