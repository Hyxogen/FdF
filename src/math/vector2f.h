/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector2f.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 08:14:43 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/24 08:25:38 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2F_H
# define VECTOR2F_H

# include "vector4f.h"
# include "util/types.h"

typedef struct s_vector2f {
	t_fl32	m_x;
	t_fl32	m_y;
}	t_vector2f;

void	vector2f_convert4f(t_vector2f *out, t_vector4f *points, t_size n);
#endif
