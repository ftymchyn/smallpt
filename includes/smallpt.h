/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallpt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:58:41 by ftymchyn          #+#    #+#             */
/*   Updated: 2018/03/19 12:58:43 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMALLPT_H
# define SMALLPT_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "SDL.h"
# include "typedefs.h"

# define SDL_ERROR "./smallpt: SDL Error : "
# define MALLOC_ERR "./smallpt: malloc allocation fails"

# define PUT_PIXEL(pixels, width, x, y, c) (pixels[y * width + x] = c)

void		initialize_sdl(t_sdl *sdl, int width, int height);
void		initialize_scene(t_scene *s);
void		wait_events(t_smallpt *pt);
void		draw_picture(t_sdl *sdl);
void		check_error(t_bool flag, char *err1, char *err2);

t_ray		ray(t_vec o, t_vec d);
t_sphere	sphere(double r, t_vec p, t_vec e, t_vec c, t_refl refl);
double		sphere_intersect(t_sphere *s, t_ray r);

double		dot(t_vec a, t_vec b);
double		v_len(t_vec v);
t_vec		norm(t_vec v);
t_vec		cross(t_vec a, t_vec b);
#endif
