/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_loop_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 19:08:20 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/03 19:52:34 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf_loop_hook(void *env)
{
	(void)env;
	write(1, "@", 1);
	return (0);
}