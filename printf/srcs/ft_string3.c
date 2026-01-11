/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:42:58 by ade-sarr          #+#    #+#             */
/*   Updated: 2026/01/11 23:48:38 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str_nbr.h"
#include <stdlib.h>

/* Variante de ft_strlcpy() : renvoie la longueur copiée
*/
size_t	ft_strlencpy(char *dest, const char *src, size_t size)
{
	size_t	n;
	size_t	l;

	l = 0;
	if (size > 0)
	{
		n = size - 1;
		while (*src && n)
		{
			*dest++ = *src++;
			n--;
			l++;
		}
		*dest = '\0';
	}
	return (l);
}

/* Copie <src> dans <dest> et renvoie la longueur de <dest>
*/
size_t	ft_strcpylen(char *dest, const char *src)
{
	size_t	l;

	l = 0;
	while (*src)
	{
		*dest++ = *src++;
		l++;
	}
	*dest = '\0';
	return (l);
}

/* idem strlcpy mais avec un entier qui sera conertit en string comme source
*/
size_t	ft_strlcpynum(char *dst, int num, size_t size)
{
	size_t	ret;
	char *const	snum = ft_itoa_m(num);

	ret = ft_strlcpy(dst, snum, size);
	free(snum);
	return (ret);
}
