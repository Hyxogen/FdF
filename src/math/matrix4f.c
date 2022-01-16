#include "matrix4f.h"
#include <ft_string.h>

t_matrix4f matrix4f_ortho(const t_ortho_settings *proj) {
	t_matrix4f ret;

	ft_memset(&ret, 0, sizeof(t_matrix4f));
	ret.u_data.m_elements[0 + 0 * 4] = 2.0f / (proj->m_right - proj->m_left);
	ret.u_data.m_elements[1 + 1 * 4] = 2.0f / (proj->m_top - proj->m_bottom);
	ret.u_data.m_elements[2 + 2 * 4] = 2.0f / (proj->m_far - proj->m_near);
	ret.u_data.m_elements[3 + 0 * 4] = -(proj->m_right + proj->m_left) / (proj->m_right - proj->m_left);
	ret.u_data.m_elements[3 + 1 * 4] = -(proj->m_top + proj->m_bottom) / (proj->m_top - proj->m_bottom);
	ret.u_data.m_elements[3 + 2 * 4] = -(proj->m_far + proj->m_near) / (proj->m_far - proj->m_near);
	ret.u_data.m_elements[3 + 3 * 4] = 1.0f;
	return (ret);
}
