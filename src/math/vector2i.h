/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector2i.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 09:58:23 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/24 08:35:22 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2I_H
# define VECTOR2I_H

# include "vector4f.h"
# include "vector2f.h"
# include "../util/types.h"

typedef struct s_vector2i {
	t_int32	m_x;
	t_int32	m_y;
}	t_vector2i;

t_vector2i	vector2i_zero(void);

t_vector2i	vector2i(t_int32 x, t_int32 y);

void		vector2i_convert4f(t_vector2i *out,
				const t_vector4f *points, t_size n);
void		vector2i_convert2f(t_vector2i *out,
				const t_vector2f *points, t_size n);
#endif
