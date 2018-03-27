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

typedef unsigned char	t_uchar;
typedef unsigned short	t_ushort;
typedef double			t_vec __attribute__((vector_size(sizeof(double)*3)));

typedef enum			e_bool
{
	FALSE, TRUE
}						t_bool;

typedef enum			e_refl
{
	DIFF, SPEC, REFR
}						t_refl;

typedef union			u_color
{
	t_uchar				byte[4];
	int					val;
}						t_color;

typedef struct			s_ray
{
	t_vec				o;
	t_vec				d;
}						t_ray;

typedef struct			s_sphere
{
	double				r;
	t_vec				p;
	t_vec				e;
	t_vec				c;
	t_refl				refl;
}						t_sphere;

typedef struct			s_camera
{
	t_vec				o;
	t_vec				d;
	t_vec				cx;
	t_vec				cy;
}						t_camera;

typedef struct			s_sdl
{
	SDL_Window			*window;
	SDL_Renderer		*renderer;
	SDL_Texture			*canvas;
	int					width;
	int					height;
	int					*pixels;
}						t_sdl;

typedef struct			s_scene
{
	t_sphere			*obj;
	int					num_obj;
	t_camera			cam;
}						t_scene;

typedef struct			s_smallpt
{
	int					id;
	t_sdl				sdl;
	t_scene				scene;
	t_ushort			xi[3];
}						t_smallpt;

#endif
