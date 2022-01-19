/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix4f_clear.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 09:06:16 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/19 09:07:30 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../matrix4f.h"
#include <ft_string.h>

void
	matrix4f_clear(t_matrix4f *mat)
{
	ft_memset(mat, 0, sizeof(t_matrix4f));
}
