/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:35:25 by ftymchyn          #+#    #+#             */
/*   Updated: 2018/03/20 13:35:27 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smallpt.h"

double		sphere_intersect(t_sphere *s, t_ray r)
{
	t_vec	op;
	double	b;
	double	dis;
	double	t;

	op = s->p - r.o;
	b = dot(op, r.d);
	dis = b * b - dot(op, op) + s->r * s->r;
	if (dis < 0)
		return 0;
	dis = sqrt(dis);
	return (t = b - dis) > 1e-4 ? t : ((t + dis) > 1e-4 ? t : 0);
}

t_sphere	sphere(double r, t_vec p, t_vec e, t_vec c, t_refl refl)
{
	t_sphere s;

	s.r = r;
	s.p = p;
	s.e = e;
	s.c = c;
	s.refl = refl;
	return (s);
}
