/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   assert.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 15:50:28 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/18 15:58:41 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSERT_H
# define ASSERT_H

# include <ft_stdbool.h>

void	debug_assert(t_bool assertion);
void	always_assert(t_bool assertion);
#endif
