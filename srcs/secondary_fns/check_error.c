/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:42:50 by ftymchyn          #+#    #+#             */
/*   Updated: 2018/03/19 14:42:51 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smallpt.h"

void		check_error(t_bool flag, char *err1, char *err2)
{
	if (flag)
	{
		if (err2 != NULL)
			dprintf(2, "%s %s\n", err1, err2);
		else
			dprintf(2, "%s\n", err1);
		exit(0);
	}
}
