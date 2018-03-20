/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:22:44 by ftymchyn          #+#    #+#             */
/*   Updated: 2018/03/19 13:22:46 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

typedef double		t_vec __attribute__((vector_size(sizeof(double)*3)));

typedef enum		e_bool
{
	FALSE, TRUE
}					t_bool;

typedef enum		e_refl
{
	DIFF, SPEC, REFR
}					t_refl;

typedef struct		s_ray
{
	t_vec			o;
	t_vec			d;
}					t_ray;

typedef struct		s_sphere
{
	double			r;
	t_vec			p;
	t_vec			e;
	t_vec			c;
	t_refl			refl;
}					t_sphere;

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*canvas;
	int				width;
	int				height;
	int				*pixels;
}					t_sdl;

typedef struct		s_scene
{
	t_sphere		*obj;
	int				num_obj;
}					t_scene;

typedef struct		s_smallpt
{
	int				id;
	t_sdl			sdl;
	t_scene			scene;
}					t_smallpt;

#endif
