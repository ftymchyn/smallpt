/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:38:37 by ftymchyn          #+#    #+#             */
/*   Updated: 2018/03/20 13:38:38 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smallpt.h"

t_bool	intersect(t_scene *s, t_ray *r, double *t, int *id)
{
	int		i;
	double	d;
	double	inf;

	inf = 1e20;
	*t = 1e20;
	i = 0;
	while (i < s->num_obj)
	{
		if ((d = sphere_intersect(&s->obj[i], r) && d < *t))
		{
			*t = d;
			*id = i;
		}
		i++;
	}
	return (*t < inf);
}
