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
# include <pthread.h>
# include "SDL.h"
# include "typedefs.h"

# define SDL_ERROR "./smallpt: SDL Error : "
# define MALLOC_ERR "./smallpt: malloc allocation fails"
# define THR_ERR "./smallpt: THREAD ERROR: can't create/join thread"
# define THREADS 4
# define SAMPLES 10
# define ADD_SAMPLE(p, w, x, y, c) (p[y * w + x] = averaged(p[y * w + x], c))

void		initialize_sdl(t_sdl *sdl, int width, int height);
void		initialize_scene(t_scene *s);
void		initialize_camera(t_scene *s, int w, int h);
void		render(t_smallpt *smallpt);
t_vec       radiance(t_smallpt *pt, t_ray r, t_ushort *xi);
t_surface   get_surface_properties(t_smallpt *pt, t_ray r, double t, int id);
t_ray       diffuse_reflection(t_surface s, t_ushort *xi);
void		wait_events(t_smallpt *pt);
void		draw_picture(t_sdl *sdl);

t_ray		ray(t_vec o, t_vec d);
t_bool		intersect(t_scene *s, t_ray *r, double *t, int *id);
t_sphere	sphere(double r, t_vec p, t_vec e, t_vec c, t_refl refl);
double		sphere_intersect(t_sphere *s, t_ray *r);

double		dot(t_vec a, t_vec b);
double		v_len(t_vec v);
t_vec		norm(t_vec v);
t_vec		cross(t_vec a, t_vec b);
void		check_error(t_bool flag, char *err1, char *err2);
double		clamp(double x);
int			to_int(t_vec v);
int			averaged(int c_1, int c_2);
void        image_to_file(t_smallpt *pt, char *file);
#endif
