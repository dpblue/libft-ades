/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:39:05 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/05/27 23:07:05 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str_nbr.h"
#include "ft_math.h"
#include <math.h>
#include <stdio.h>

#define ARR arrangement
#define CMB combination

void	math_test(void)
{
	printf("math_test: power, factorial, arrangement, combination\n");
	printf("2^8=%lld, 10^6=%lld, -4^3=%lld, 0^0=%lld 0^1=%lld, "
		"50^-1=%lld\n", power(2, 8), power(10, 6), power(-4, 3),
		power(0, 0), power(0, 1), power(50, -1));
	printf("0!=%lld, 1!=%lld, 2!=%lld, 3!=%lld, 4!=%lld\n",
		factorial(0), factorial(1), factorial(2), factorial(3), factorial(4));
	printf("A(0,0)=%lld, A(0,9)=%lld, A(1,0)=%lld, A(1,1)=%lld, A(8,8)=%lld, "
		"A(9,10)=%lld\n", ARR(0, 0), ARR(0, 9), ARR(1, 0), ARR(1, 1),
		ARR(8, 8), ARR(9, 10));
	printf("C(0,0)=%lld, C(0,9)=%lld, C(1,0)=%lld, C(1,1)=%lld, C(8,8)=%lld, "
		"C(9,10)=%lld\n", CMB(0, 0), CMB(0, 9), CMB(1, 0), CMB(1, 1),
		CMB(8, 8), CMB(9, 10));
}

void	test_ft_ln_vs_log(void)
{
	double	i;
	for (i = 0.0; i <= 2.0; i += 0.1)
	{
		printf   ("   [printf] ln(%f) = %f  log: %f\n", i, ft_ln(i), log(i));
		ft_printf("[ft_printf] ln(%f) = %f  log: %f\n", i, ft_ln(i), log(i));
	}
	i = 10.0;
	printf   ("   [printf] ln(%f) = %f  log: %f\n", i, ft_ln(i), log(i));
	ft_printf("[ft_printf] ln(%f) = %f  log: %f\n", i, ft_ln(i), log(i));
}

/* Programme de test de libftprintf
*/
int main(void)
{
	test_ft_printf();
	/*ft_putchar('\n');
	math_test();
	ft_putchar('\n');
	test_ft_ln_vs_log();
	ft_putchar('\n');
	test_ft_ln();*/
	return (0);
}