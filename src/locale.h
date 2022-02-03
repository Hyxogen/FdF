/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   locale.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 07:55:23 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/03 16:11:51 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOCALE_H
# define LOCALE_H

# ifndef FDF_MSG_ARGS_INVALID
#  define FDF_MSG_ARGS_INVALID "Invalid arguments. Usage: ./fdf {path-to-map}\n"
# endif

# ifndef FDF_MSG_MAP_LOAD_FAIL
#  define FDF_MSG_MAP_LOAD_FAIL "Failed to load map. \
Did you check the path?\n"
# endif

# ifndef FDF_WINDOW_NAME
#  define FDF_WINDOW_NAME "fdf"
# endif

#endif
