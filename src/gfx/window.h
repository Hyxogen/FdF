/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 15:00:42 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/19 09:13:08 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <ft_stdbool.h>

typedef struct s_window {
	int		m_width;
	int		m_height;
	char	*m_title;
	void	*m_window_handle;
	void	*m_mlx_handle;
}	t_window;

t_bool		_window_init(t_window *window, char *title, int width, int height);

/*MALLOC SAFE*/
t_window	*window_create(void *mlx, char *title, int width, int height);
void		window_destroy(t_window *window, t_bool free_self);

void		window_update(t_window *window);
#endif
