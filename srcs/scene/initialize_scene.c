/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_scene.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:36:47 by ftymchyn          #+#    #+#             */
/*   Updated: 2018/03/20 13:36:48 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smallpt.h"

void	initialize_scene(t_scene *s)
{
	s->num_obj = 9;

	s->obj = (t_sphere*)malloc(sizeof(t_sphere) * s->num_obj);
	check_error(!s->obj, MALLOC_ERR, NULL);
	s->obj[0] = sphere(1e5, (t_vec){1e5 + 1, 40.8, 81.6},
		(t_vec){0, 0, 0}, (t_vec){.75, .25, .25}, DIFF);
	s->obj[1] = sphere(1e5, (t_vec){-1e5 + 99, 40.8, 81.6},
		(t_vec){0, 0, 0}, (t_vec){.25, .25, .75}, DIFF);
	s->obj[2] = sphere(1e5, (t_vec){50, 40.8, 1e5},
		(t_vec){0, 0, 0}, (t_vec){.75, .75, .75}, DIFF);
	s->obj[3] = sphere(1e5, (t_vec){50, 40.8, -1e5 + 170},
		(t_vec){0, 0, 0}, (t_vec){0, 0, 0}, DIFF);
	s->obj[4] = sphere(1e5, (t_vec){50, 1e5, 81.6},
		(t_vec){0, 0, 0}, (t_vec){.75, .75, .75}, DIFF);
	s->obj[5] = sphere(1e5, (t_vec){50, -1e5 + 81.6, 81.6},
		(t_vec){0, 0, 0}, (t_vec){.75, .75, .75}, DIFF);
	s->obj[6] = sphere(16.5, (t_vec){27, 16.5, 47},
		(t_vec){0, 0, 0}, (t_vec){1, 1, 1}, DIFF);
	s->obj[7] = sphere(16.5, (t_vec){73, 16.5, 78},
		(t_vec){0, 0, 0}, (t_vec){1, 1, 1}, DIFF);
	s->obj[8] = sphere(1.5, (t_vec){50, 81.6 - 16.5, 81.6},
		(t_vec){400, 400, 400}, (t_vec){0, 0, 0}, DIFF);
}
