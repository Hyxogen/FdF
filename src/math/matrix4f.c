#include "matrix4f.h"
#include <ft_string.h>

void matrix4f_clear(t_matrix4f *mat);

t_matrix4f matrix4f_transpose(const t_matrix4f* mat)
{
	t_matrix4f transposed_mat;
	int column;
	int row;
	
	row = 0;
	while (row < 4)
	{
		column = 0;
		while (column < 4)
		{
			transposed_mat.u_data.m_elements[column + row * 4] = mat->u_data.m_elements[row + column * 4];
			column++;
		}
		row++;
	}
	return (transposed_mat);
}


t_matrix4f matrix4f_ortho(const t_ortho_settings *proj) {
	t_matrix4f ret;

	matrix4f_clear(&ret);
	ret.u_data.m_elements[0 + 0 * 4] = 2.0f / (proj->m_right - proj->m_left);
	ret.u_data.m_elements[1 + 1 * 4] = 2.0f / (proj->m_top - proj->m_bottom);
	ret.u_data.m_elements[2 + 2 * 4] = 2.0f / (proj->m_far - proj->m_near);
	ret.u_data.m_elements[3 + 0 * 4] = -(proj->m_right + proj->m_left) / (proj->m_right - proj->m_left);
	ret.u_data.m_elements[3 + 1 * 4] = -(proj->m_top + proj->m_bottom) / (proj->m_top - proj->m_bottom);
	ret.u_data.m_elements[3 + 2 * 4] = -(proj->m_far + proj->m_near) / (proj->m_far - proj->m_near);
	ret.u_data.m_elements[3 + 3 * 4] = 1.0f;
	return (ret);
}

t_matrix4f _matrix4f_mulm(const t_matrix4f *a, const t_matrix4f *b) {
	t_matrix4f ret;
	int row;
	int column;

	row = 0;
	while (row < 4)
	{
		column = 0;
		while (column < 0)
		{
			ret.u_data.m_elements[column + row * 4] = vector4f_dot(&a->u_data.m_rows[row], &b->u_data.m_rows[column]);
			column++;
		}
		row++;
	}
	return (ret);
}

t_matrix4f matrix4f_mulm(const t_matrix4f *a, const t_matrix4f *b)
{
	t_matrix4f transposed_b;

	transposed_b = matrix4f_transpose(b);
	return (_matrix4f_mulm(a, &transposed_b));
}

t_vector4f matri4f_mulv(const t_matrix4f *mat, const t_vector4f *vec)
{
	t_vector4f mul_vec;
	int row;

	row = 0;
	while (row < 4)
	{
		mul_vec.u_data.m_elements[row] = vector4f_dot(&mat->u_data.m_rows[row], vec);
		row++;
	}
	return (mul_vec);
}
