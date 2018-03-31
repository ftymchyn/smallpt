/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:54:27 by ftymchyn          #+#    #+#             */
/*   Updated: 2018/03/20 15:55:05 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smallpt.h"

static t_vec	compute_pixel_color(t_smallpt *pt, int x, int y, t_ushort *xi)
{
	double	r1;
	double	r2;
	double	dx;
	double	dy;
	t_vec	rad = {0, 0, 0};
	t_vec	res = {0, 0, 0};
	t_vec	d;

	for (size_t sy = 0; sy < 2; sy++)
	{
		for (size_t sx = 0; sx < 2; sx++)
		{
			for (size_t s = 0; s < SAMPLES; s++)
			{
				r1 = 2 * erand48(xi);
				r2 = 2 * erand48(xi);
				dx = (r1 < 1) ? sqrt(r1) - 1 : 1 - sqrt(2 - r1);
				dy = (r2 < 1) ? sqrt(r2) - 1 : 1 - sqrt(2 - r2);
				dx = ((sx + 0.5 + dx) / 2.0 + x) / (double)pt->sdl.width - 0.5;
				dy = ((sy + 0.5 + dy) / 2.0 + y) / (double)pt->sdl.height - 0.5;
				d = pt->scene.cam.cx * (t_vec){dx, dx, dx} +
					pt->scene.cam.cy * (t_vec){dy, dy, dy} + pt->scene.cam.d;
				rad += radiance(
						pt,
						ray(
							pt->scene.cam.o + (t_vec){140, 140, 140} * d,
							norm(d)),
						xi) *
					(t_vec){1.0 / SAMPLES, 1.0 / SAMPLES, 1.0 / SAMPLES};
			}
			res += (t_vec){clamp(rad[0]), clamp(rad[1]), clamp(rad[2])} *
					(t_vec){.25, .25, .25};
		}
	}
	return (res);
}

static void		*thread_render(void *smallpt)
{
	t_smallpt	*pt;
	t_vec		col;
	t_ushort	xi[3];
	int			x;
	int			y;
	int			y_end;

	pt = (t_smallpt*)smallpt;
	y = pt->id * (pt->sdl.height / THREADS) - 1;
	y_end = (y + 1) + pt->sdl.height / THREADS;
	while (++y < y_end)
	{
		x = 0;
		xi[0] = 0;
		xi[1] = 0;
		xi[2] = y * y * y;
		while (x < pt->sdl.width)
		{
			col = compute_pixel_color(pt, x, y, xi);
			ADD_SAMPLE(pt->sdl.pixels, pt->sdl.width,
				x, (pt->sdl.height - y - 1), to_int(col));
			x++;
		}
	}
	return (NULL);
}

void			render(t_smallpt *smallpt)
{
	pthread_t	thr[THREADS];
	t_smallpt	pt[THREADS];
	int			i;
	int			status;

	i = -1;
	while (++i < THREADS)
	{
		pt[i] = *smallpt;
		pt[i].id = i;
		status = pthread_create(thr + i, NULL, thread_render, pt + i);
		check_error(status != 0, THR_ERR, NULL);
	}
	i = -1;
	while (++i < THREADS)
	{
		status = pthread_join(thr[i], NULL);
		check_error(status != 0, THR_ERR, NULL);
	}
	//draw_picture(&smallpt->sdl);
}
