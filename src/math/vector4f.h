#ifndef VERCTOR4F_H
# define VERCTOR4F_H

typedef struct s_vector4f {
	float m_x;
	float m_y;
	float m_z;
	float m_w;
}	t_vector4f;

t_vector4f* vector4f_add(const t_vector4f *a, const t_vector4f *b, t_vector4f *out);

t_vector4f* vector4f_muls(const t_vector4f *a, float scalar, t_vector4f* out);
#endif
