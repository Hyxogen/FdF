/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_parser.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 10:13:00 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/24 10:17:41 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSER_H
# define MAP_PARSER_H

# include "util/types.h"

t_int32	*parser_parse_map(const char *map_str, t_size len);

#endif
