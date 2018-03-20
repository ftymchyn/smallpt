/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:58:53 by ftymchyn          #+#    #+#             */
/*   Updated: 2018/03/19 12:58:55 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smallpt.h"

int	main(void)
{
	t_smallpt	pt;

	initialize_sdl(&pt.sdl, 1024, 768);
	initialize_scene(&pt.scene);
	wait_events(&pt);
	return (0);
}
