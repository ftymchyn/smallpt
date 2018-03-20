/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_camera.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:05:05 by ftymchyn          #+#    #+#             */
/*   Updated: 2018/03/20 17:05:06 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smallpt.h"

void	initialize_camera(t_scene *s, int w, int h)
{
	s->cam.o = (t_vec){50, 52, 295.6};
	s->cam.d = norm((t_vec){0, -0.042612, -1});
	s->cam.cx = (t_vec){w * .5135 / (double)h, 0, 0};
	s->cam.cy = norm(cross(s->cam.cx, s->cam.d)) * (t_vec){.5135, .5135, .5135};
}
