/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:06:39 by ftymchyn          #+#    #+#             */
/*   Updated: 2018/03/19 18:06:41 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smallpt.h"

double	dot(t_vec a, t_vec b)
{
	return (a[0] * b[0] + a[1] * b[1] + a[2] * b[2]);
}
