/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   platform.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 15:05:41 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/02 15:23:10 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLATFORM_H
# define PLATFORM_H

# ifdef FDF_PLATFORM_LINUX
#  define _POSIX_C_SOURCE 200112L
#  define __USE_MISC
#  define _ISO99_SOURCE
# endif

#endif
