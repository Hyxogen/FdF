#include "../matrix4f.h"

t_matrix4f
	matrix4f_sscale(t_fl32 x, t_fl32 y, t_fl32 z)
{
	t_matrix4f	ret;

	matrix4f_clear(&ret);
	ret.m_elements[0 + 0 * 4] = x;
	ret.m_elements[1 + 1 * 4] = y;
	ret.m_elements[2 + 2 * 4] = z;
	ret.m_elements[3 + 3 * 4] = 1.0f;
	return (ret);
}

t_matrix4f
	matrix4f_vscale(t_vector3f scale)
{
	return (matrix4f_sscale(scale.m_x, scale.m_y, scale.m_z));
}

t_matrix4f
	matrix4f_usscale(t_fl32 scalar)
{
	return (matrix4f_sscale(scalar, scalar, scalar));
}

