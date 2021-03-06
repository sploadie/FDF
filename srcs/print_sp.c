/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 14:28:18 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/03 09:41:27 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_sp_left(char *str, size_t space)
{
	size_t	size;

	size = ft_strlen(str);
	while (space > size)
	{
		write(1, " ", 1);
		space--;
	}
	write(1, str, space);
}

void	print_sp_right(char *str, size_t space)
{
	size_t	size;

	size = ft_strlen(str);
	if (space < size)
		write(1, str, space);
	else
		write(1, str, size);
	while (space > size)
	{
		write(1, " ", 1);
		space--;
	}
}
