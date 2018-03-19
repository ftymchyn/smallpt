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
# include "SDL.h"
# include "typedefs.h"

# define SDL_ERROR "./smallpt: SDL Error : "
# define MALLOC_ERR "./smallpt: malloc allocation fails"

# define PUT_PIXEL(pixels, width, x, y, c) (pixels[y * width + x] = c)

void	initialize_sdl(t_sdl *sdl, int width, int height);
void	wait_events(t_sdl *sdl);
void	draw_picture(t_sdl *sdl);
void	check_error(t_bool flag, char *err1, char *err2);

#endif
