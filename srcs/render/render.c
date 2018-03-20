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

static void		*thread_render(void *smallpt)
{
	t_smallpt	*pt;
	t_vec		col;
	int			x;
	int			y;
	int			y_end;

	pt = (t_smallpt*)smallpt;
	y = pt->id * (pt->sdl.height / THREADS) - 1;
	y_end = (y + 1) + pt->sdl.height / THREADS;
	while (++y < y_end)
	{
		x = 0;
		while (x < pt->sdl.width)
		{
			col = (t_vec){.25, .25, .75}; //stub, trace_path() in future
			ADD_SAMPLE(pt->sdl.pixels, pt->sdl.width, x, y, to_int(col));
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
	draw_picture(&smallpt->sdl);
}
