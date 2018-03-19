/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_picture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:36:50 by ftymchyn          #+#    #+#             */
/*   Updated: 2018/03/19 14:36:51 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smallpt.h"

void	draw_picture(t_sdl *sdl)
{
	SDL_UpdateTexture(sdl->canvas, NULL, sdl->pixels, sdl->width << 2);
	SDL_RenderClear(sdl->renderer);
	SDL_RenderCopy(sdl->renderer, sdl->canvas, NULL, NULL);
	SDL_RenderPresent(sdl->renderer);
}
