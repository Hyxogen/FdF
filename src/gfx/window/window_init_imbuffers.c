#include "../window.h"
#include "../image_buffer.h"

t_bool
	window_init_imbuffers(t_window *window)
{
	window->m_imbuffer_front = ib_create(window->m_mlx_handle, window->m_width, window->m_height);
	return (TRUE);
}

