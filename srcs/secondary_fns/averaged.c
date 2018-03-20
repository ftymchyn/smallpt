/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   averaged.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:56:10 by ftymchyn          #+#    #+#             */
/*   Updated: 2018/03/20 17:56:11 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smallpt.h"

int	averaged(int c_1, int c_2)
{
	int		i;
	t_color av;
	t_color c1;
	t_color c2;

	i = 0;
	c1.val = c_1;
	c2.val = c_2;
	while (i < 3)
	{
		av.byte[i] = (c1.byte[i] + c2.byte[i]) >> 1;
		i++;
	}
	av.byte[i] = 0;
	return (av.val);
}
