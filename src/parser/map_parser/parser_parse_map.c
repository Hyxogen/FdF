/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_parse_map.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 10:14:36 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/24 11:33:46 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../map_parser.h"
#include "util/mem_utils.h"
#include <ft_string.h>
#include <ft_ctype.h>
#include <ft_stdbool.h>
#include <ft_stdlib.h>
#include <stdio.h>

t_bool
	_parser_is_valid_entry(int c)
{
	return (c == '-' || c == '+' || ft_isdigit(c));
}

t_int32
	_parser_get_width(const char *map_str, t_size len)
{
	while (len && _parser_is_valid_entry(*map_str))
	{
		map_str++;
		len--;
	}
	if (*map_str == '\0')
		return (0);
	if (*map_str == '\n')
		return (1);
	while (len && *map_str == ' ')
	{
		map_str++;
		len--;
	}
	return (_parser_get_width(map_str, len) + 1);
}

t_int32
	_parser_get_height(const char *map_str, t_size len)
{
	char	*new_line;

	if (len == 0)
		return (0);
	new_line = ft_memchr(map_str, '\n', len);
	if (new_line == NULL)
		return (0);
	return (1 + _parser_get_height(
			new_line + 1,
			len - ((new_line - map_str) + 1)));
}

void
	_parser_fill(t_int32 *out, const char *map_str, t_size len)
{
	while (len)
	{
		while (len && (*map_str == ' ' || *map_str == '\n'))
		{
			map_str++;
			len--;
		}
		if (len)
			*out = ft_atoi(map_str);
		while (len && _parser_is_valid_entry(*map_str))
		{
			map_str++;
			len--;
		}
		while (len && (*map_str == ' ' || *map_str == '\n'))
		{
			map_str++;
			len--;
		}
		out++;
	}
}

t_int32
	*parser_parse_map(const char *map_str,
		t_size len, t_int32 *width, t_int32 *height)
{
	t_int32	*heights;

	*width = _parser_get_width(map_str, len);
	*height = _parser_get_height(map_str, len);
	if (*width * *height == 0)
		return (NULL);
	heights = safe_malloc(sizeof(t_int32) * *width * *height);
	_parser_fill(heights, map_str, len);
	return (heights);
}
