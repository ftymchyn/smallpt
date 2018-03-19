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
	false, true
}					t_bool;

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*canvas;
	int				width;
	int				height;
	int				*pixels;
}					t_sdl;

typedef struct		s_smallpt
{
	int				id;
	t_sdl			sdl;
}					t_smallpt;

#endif
