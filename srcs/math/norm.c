/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftymchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:06:51 by ftymchyn          #+#    #+#             */
/*   Updated: 2018/03/19 18:06:53 by ftymchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smallpt.h"

t_vec	norm(t_vec v)
{
	double len;
	double inv_len;

	len = v_len(v);
	if (len > 0)
	{
		inv_len = 1.0 / len;
		return (v * (t_vec){inv_len, inv_len, inv_len});
	}
	return (v);
}
