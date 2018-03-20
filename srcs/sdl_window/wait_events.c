/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 16:08:00 by ftymchyn          #+#    #+#             */
/*   Updated: 2018/03/19 16:08:02 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smallpt.h"

static t_bool	pull_event(SDL_Event *e)
{
	while (SDL_PollEvent(e))
	{
		if (e->type == SDL_QUIT
			|| (e->type == SDL_KEYDOWN && !e->key.repeat)
			|| (e->type == SDL_KEYUP && !e->key.repeat))
			return (TRUE);
	}
	return (FALSE);
}

void			wait_events(t_smallpt *pt)
{
	SDL_Event		e;

	while (1)
	{
		if (pull_event(&e))
		{
			if (e.type == SDL_QUIT ||
				(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE))
				return ;
		}
		draw_picture(&pt->sdl);
	}
}
