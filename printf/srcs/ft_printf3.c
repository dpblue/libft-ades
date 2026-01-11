/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 22:49:05 by ade-sarr          #+#    #+#             */
/*   Updated: 2026/01/11 23:55:24 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str_nbr.h"
#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	count = ft_vdprintf(1, format, args);
	va_end(args);
	return (count);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		count;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	count = ft_vdprintf(fd, format, args);
	va_end(args);
	return (count);
}

int	ft_vprintf(const char *format, va_list args)
{
	return ft_vdprintf(1, format, args);
}
