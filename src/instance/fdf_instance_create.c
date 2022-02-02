/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_instance_create.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 07:56:08 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/02 07:56:10 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "util/mem_utils.h"
#include <stddef.h>

t_fdf	
	*fdf_instance_create(void)
{
	t_fdf	*instance;

	instance = safe_malloc(sizeof(t_fdf));
	fdf_instance_init(instance, NULL, NULL, NULL);
	return (instance);
}
