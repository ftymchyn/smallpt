/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:14:00 by ftymchyn          #+#    #+#             */
/*   Updated: 2018/03/20 15:14:02 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smallpt.h"

int	to_int(t_vec v)
{
	int		i;
	t_color	c;

	i = 0;
	while (i < 3)
	{
		c.byte[i] = (int)(clamp(v[i]) * 255 + .5);
		i++;
	}
	c.byte[i] = 0x0;
	return (c.val);
}