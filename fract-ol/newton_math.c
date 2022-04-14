/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:21:14 by gyepark           #+#    #+#             */
/*   Updated: 2022/04/14 15:21:15 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static t_complex	get_complex_pow_2(t_complex v)
{
	t_complex	res;
	double		temp_re;

	temp_re = v.re;
	res.re = v.re * v.re - v.im * v.im;
	res.im = 2 * temp_re * v.im;
	return (res);
}

static t_complex	get_complex_pow_3(t_complex v)
{
	t_complex	res;

	res.re = pow(v.re, 3) - 3 * v.re * v.im * v.im;
	res.im = -pow(v.im, 3) + 3 * v.re * v.re * v.im;
	return (res);
}

static t_complex	get_func_value(t_complex v)
{
	t_complex	res;

	res = get_complex_pow_3(v);
	res.re -= 1;
	return (res);
}

static t_complex	get_derivative_value(t_complex v)
{
	t_complex	res;

	res = get_complex_pow_2(v);
	res.re *= 3;
	res.im *= 3;
	return (res);
}

t_complex	divide_func_derivative(t_complex v)
{
	t_complex	res;
	t_complex	p;
	t_complex	p_prime;
	double		divider;

	p = get_func_value(v);
	p_prime = get_derivative_value(v);
	divider = p_prime.re * p_prime.re + p_prime.im * p_prime.im;
	res.re = (p.re * p_prime.re + p.im * p_prime.im) / divider;
	res.im = (p.im * p_prime.re - p.re * p_prime.im) / divider;
	return (res);
}
