/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_len.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:07:39 by ftymchyn          #+#    #+#             */
/*   Updated: 2018/03/19 18:07:41 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smallpt.h"

double	v_len(t_vec v)
{
	return (sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]));
}