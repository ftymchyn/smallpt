/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_sdl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:35:42 by ftymchyn          #+#    #+#             */
/*   Updated: 2018/03/19 14:35:44 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smallpt.h"

void	initialize_sdl(t_sdl *sdl, int width, int height)
{
	check_error(SDL_Init(SDL_INIT_VIDEO) < 0, SDL_ERROR, (char*)SDL_GetError());
	sdl->window = SDL_CreateWindow(
		"smallpt",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		0);
	check_error(!sdl->window, SDL_ERROR, (char*)SDL_GetError());
	sdl->renderer = SDL_CreateRenderer(
		sdl->window,
		-1,
		SDL_RENDERER_ACCELERATED);
	check_error(!sdl->renderer, SDL_ERROR, (char*)SDL_GetError());
	sdl->canvas = SDL_CreateTexture(
		sdl->renderer,
		SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_TARGET,
		width,
		height);
	check_error(!sdl->canvas, SDL_ERROR, (char*)SDL_GetError());
	sdl->width = width;
	sdl->height = height;
	sdl->pixels = (int*)malloc(sizeof(int) * (sdl->width * sdl->height));
	check_error(!sdl->pixels, MALLOC_ERR, NULL);
}
