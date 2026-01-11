/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:39:05 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/03/08 20:39:08 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str_nbr.h"
#include <stdio.h>

bool	cmp_vsp(char *format, ...)
{
	char	buffer1[4096];
	char	buffer2[4096];
	int		count1;
	int		count2;
	va_list	args;

	va_start(args, format);
	count1 = vsprintf(buffer1, format, args);
	va_end(args);
	va_start(args, format);
	count2 = ft_vsprintf(buffer2, format, args);
	va_end(args);
	if (ft_strcmp(buffer1, buffer2) == 0)
	{
		ft_printf("[Ok] %s -> %s\n", format, buffer1);
		return (true);
	}
	ft_printf("[BAD] %s\n  [vsprintf]    -> %s\n  [ft_vsprintf] -> %s\n",
		format, buffer1, buffer2);
	(void)count1;
	(void)count2;
	return (false);
}

void	test_simple_and_double(void)
{
	int			i;
	const char	*h = "Hello!";

	i = 0xAF;
	ft_printf(">>> Test de la fonction ft_printf\n");
	ft_printf("%i%d=%s\n", 4, 2, "42");
	ft_printf("%i%d=%s\n", 42, 24, "4224");
	ft_printf("nombre %i : base 2: %b  base 10: %d  base 16: %#x (%#X)\n",
		i, i, i, i, i);
	ft_printf("%c%c%c%c%c%c\n", 'H', 'e', 'l', 'l', 'o', '!');
	ft_printf("%c%c%c%c%c%c\n", h[0], h[1], h[2], h[3], h[4], h[5]);
	ft_printf("pointeur : [%p]\n", &i);
	ft_printf("\n");
	ft_printf("dec: %F  hex: %F  bin: %F\n",
		-1.75, 10, 2, -1.75, 16, 13, -1.75, 2, 52);
	ft_printf("dec: %F  hex: %F  bin: %F\n",
		999.14159e123, 10, 6, 999.14159e123, 16, 100, 999.14159e123, 2, 100);
	ft_printf("  %f : %B-1f\n", 999.14159e123, 999.14159e123);
	ft_printf("  %f : %B-1f\n", 3.0, 3.0);
	ft_printf("%f : %B-1f\n", -1.75, -1.75);
	ft_printf("  %f : %B-1f\n", 1e300 * 1e300, 1e300 * 1e300);
	ft_printf("  %f : %B-1f\n", 0.0 / 0.0, 0.0 / 0.0);
}

#define _WIDTH 28

void	test_ft_itoa(void)
{
	t_i2s_fmt	fmt;
	char		buf[80];

	ft_printf("\n%d : %s\n", 314, ft_itoa(314, 10, i2s_len(8, '.'), buf));
	ft_printf("  %d : %s\n", 0, ft_itoa(0, 10, 8, buf));
	i2sfmt_set(&fmt, 10, 0, i2s_sep(3, ' ', false));
	ft_printf("d : %s$\n", ft_itoa_ex(-123456789, &fmt, buf));
	i2sfmt_set(&fmt, 10, i2s_len(_WIDTH, '.'), i2s_sep(3, ' ', false));
	ft_printf("d : %s$\n", ft_itoa_ex(-123456789, &fmt, buf));
	i2sfmt_set(&fmt, 10, i2s_len_j(_WIDTH, '.', true, true),
		i2s_sep(3, ' ', false));
	ft_printf("d : %s$\n", ft_itoa_ex(-123456789, &fmt, buf));
	i2sfmt_set(&fmt, 10, i2s_len_j(_WIDTH, '0', false, true),
		i2s_sep(3, ' ', true));
	ft_printf("d : %s$\n", ft_itoa_ex(-123456789, &fmt, buf));
	i2sfmt_set(&fmt, 10, i2s_len_j(_WIDTH, '.', false, false),
		i2s_sep(3, ' ', true));
	ft_printf("d : %s$\n", ft_ltoa_ex(-9, &fmt, buf));
	i2sfmt_set(&fmt, 16, i2s_len_j(_WIDTH, '.', false, true),
		i2s_sep(4, ' ', true));
	i2sfmt_setstr(&fmt, "(neg)", "+", NULL);
	ft_printf("d : %s$\n", ft_ltoa_ex(-0x7edcba9876543210, &fmt, buf));
	i2sfmt_set(&fmt, i2s_base(36, true, true),
		i2s_len_j(_WIDTH, '.', false, true), i2s_sep(1, ' ', true));
	ft_printf("d : %s$\n", ft_ltoa_ex(0x7edcba9876543210, &fmt, buf));
}

void	test_ft_printf(void)
{
	const char		*null = NULL;
	int				i;
	long int		l;
	t_uint			u;
	unsigned long	ul;
	const char		*h = "Hello!";

	test_simple_and_double();
	test_ft_itoa();
	ft_printf("\n");
	cmp_vsp(    "\"%17s\"", "printf %s test");
	cmp_vsp("\"%-17.20s\"", "printf %s test");
	cmp_vsp(     "\"%5s\"", "printf %s test");
	cmp_vsp(  "\"%5.11s\"", "printf %s test");
	cmp_vsp(  "\"%-.11s\"", "printf %s test");
	ft_printf("\n");
	cmp_vsp("decimal \"%%+10d\" : %+10d", 1234567);
	cmp_vsp("decimal \"%%+010d\": %+010d", 1234567);
	printf   ("unsigned: % -20li$\n", 0xffffffffff);
	ft_printf("unsigned: % -20l$\n",  0xffffffffff);
	i = -1;
	u = -1;
	ul =-1;
	l = -1;
	(void)l; (void)u;
	cmp_vsp("hexa: %#10x", i/*0xffffffff*/);
	cmp_vsp("pointer: %p", h);
	cmp_vsp("double: %8.4f", 3.14159);
	//ft_printf("%l\n", -2);
	cmp_vsp("hexa: %#x  %#x  %#x", -1, 0, 1);
	cmp_vsp("unsigned int : %s%u%s", "$", u, "$");
	cmp_vsp("unsigned long: %s%u%s", "$", ul, "$");
	ft_printf("\n");
	ft_printf("ft_printf 'test' string: $%.2s$\n", "test");
	printf("   printf 'test' string: $%.2s$\n", "test");
	ft_printf("ft_printf null string: $%10.6s$\n", null);
	printf("   printf null string: $%10.6s$\n", null);
	ft_printf("ft_printf null pointer: $%10.2p$\n", null);
	printf("   printf null pointer: $%10.2p$\n", null);
	ft_printf("\n");
	printf("$%-10c$\n", 'A');
	ft_printf("$%-10c$\n", 'A');
	cmp_vsp("$%-10c$", 'A');
	cmp_vsp("$%10.0c$", 'A');
	printf("$%3c$\n", 0);
	ft_printf("$%3c$\n", 0);
	printf("$%3s$\n", "");
	ft_printf("$%3s$\n", "");
	/*cmp_vsp("$%-1c %-2c %-3c $", '1', '2', '3');
	cmp_vsp("$%-1c %-2c %-3c $", '0', 0, '1');
	cmp_vsp("$%-1c %-2c %-3c $", '2', '1', 0);
	cmp_vsp("$%-1c %-2c %-3c $", 0, '1', '2');
	printf("$%-1c %-2c %-3c $\n", '0', 126, '1');
	ft_printf("$%-1c %-2c %-3c $\n", '0', 126, '1');
	printf("$%-1c %-2c %-3c $\n", '0', 127, '1');
	ft_printf("$%-1c %-2c %-3c $\n", '0', 127, '1');
	printf("$%-1c %-2c %-3c $\n", '0', 128, '1');
	ft_printf("$%-1c %-2c %-3c $\n", '0', 128, '1');
	   printf("$%-1c %-2c %-3c $\n", '0', 0, '1');
	ft_printf("$%-1c %-2c %-3c $\n", '0', 0, '1');
	   printf("$%2c$\n", 0);
	ft_printf("$%2c$\n", 0);
	   printf("$%s$\n", "");
	ft_printf("$%s$\n", "");
	   printf("$ %-1c %-2c %-3c $\n", '0', 0, '1');
	ft_printf("$ %-1c %-2c %-3c $\n", '0', 0, '1');
	*/
	cmp_vsp("$%10.5u$", 1);
	cmp_vsp("$%010.5u$", 1);
	cmp_vsp("$%-05u$", 1);
	ft_printf("$%-5u$\n", 1);

	cmp_vsp("$%+5i$", 42);
	cmp_vsp("$%+05i$", 42);
	cmp_vsp("$%+5u$", 42);
	cmp_vsp("$%+05u$", 42);
	cmp_vsp("$%-5.2u$", 42);
	cmp_vsp("$%-5.2i$", -42);
ft_printf("\n");
	cmp_vsp("$%.0i$", 0);
	cmp_vsp("$%.i$", 0);
	cmp_vsp("$%5.0i$", 0);
	cmp_vsp("$%5.i$", 0);
	cmp_vsp("$%-5.0i$", 0);
	cmp_vsp("$%-5.i$", 0);
	cmp_vsp("$%.0d$", 0);
	cmp_vsp("$%.d$", 0);
	cmp_vsp("$%5.0d$", 0);
	cmp_vsp("$%5.d$", 0);
	cmp_vsp("$%-5.0d$", 0);
	cmp_vsp("$%-5.d$", 0);
	cmp_vsp("$%.0u$", 0);
	cmp_vsp("$%.u$", 0);
	cmp_vsp("$%5.0u$", 0);
	cmp_vsp("$%5.u$", 0);
	cmp_vsp("$%-5.0u$", 0);
	cmp_vsp("$%-5.u$", 0);
	cmp_vsp("$%.0x$", 0);
	cmp_vsp("$%.x$", 0);

	   printf("$%073.83x$\n$%00056.187d$\n$%-%$\n$%-78.56X$\n$%-104.170X$\n\n" ,898043181u,1522753180,2837283853u,207713687u);
	ft_printf("$%073.83x$\n$%00056.187d$\n$%-%$\n$%-78.56X$\n$%-104.170X$\n\n" ,898043181u,1522753180,2837283853u,207713687u);
	//return;
	
	cmp_vsp("%-153p%0110.8x%110p" ,(void*)17240180584784891087lu,2705171059u,(void*)1312307382483808423lu);
	cmp_vsp("%-163.23u%-68.0X" ,3421138903u,514939578u);
	
	cmp_vsp("$%073.83x$\n$%00056.187d$\n$%-%%-78.56X$\n$%-104.170X$" ,898043181u,1522753180,2837283853u,207713687u);
	cmp_vsp("%073.83x%00056.187d%-%%-78.56X%-104.170X" ,898043181u,1522753180,2837283853u,207713687u);
	cmp_vsp("%-193.41d%-83.75X" ,-1402064983,2109137899u);
	cmp_vsp("%--120.50d%-%%-112.167X%-32.65u" ,-1355834522,3814946551u,404243169u);
	
	cmp_vsp("%052.88i%-87.137u%--81.25X%26c%--198.131i" ,1348141248,2480967409u,3367743035u,96,340172724);
	cmp_vsp("%-77.96u%-135.50d%-%%061.149u%-122.96u" ,735543458u,1423566439,3134965784u,2213547867u);
	cmp_vsp("%0163.109u%-140.69d%---91.148s%000132.141i%-52.170x" ,2109506632u,-1086209677,"\nmD^8<.q*'\rD",-1143516304,2879456117u);
	cmp_vsp("%0%%-100.142X%-156c%-163.122d" ,966917282u,116,-1334835467);
	cmp_vsp("%-127.104s%-26.169d%--60.88i%142.52s" ,"",955786883,-1974652066,"d^ex<#[F\v>=ka/hj");
	cmp_vsp("%--81p%-115c%59s%135p%-46.34s" ,(void*)1228459267589004209lu,75,"`-@y3g&n[4!L=",(void*)7434010127989266962lu,",\v{#*|<Z,|M.OWYN@A$+r%YM:OOX");
	cmp_vsp("%--133.48i%-103.188u%0003.72X" ,1341200964,3945708301u,3224169818u);
	cmp_vsp("%-.148d%-166.126d%--137p%131c%111.86s" ,-1733961224,-1148896912,(void*)17695841004645625598lu,-90,"v-Q/)ZI3");
	cmp_vsp("%0%%0104.20x%---176p%--8.25X%-120.98i" ,462982545u,(void*)2547223992875393254lu,1267937232u,640121608);
	cmp_vsp("%--34.169x%-153c%---%%-164p" ,516530274u,-113,(void*)9877588959652347135lu);
	cmp_vsp("%090.196X%0197.108d" ,905350113u,-1350090454);
	cmp_vsp("%--140.73x%-195.97X%-58.185u%-162.133X" ,3001074927u,363790737u,1318998644u,2446287384u);
	cmp_vsp("%--139.146d%127.161s%--71p%--27.141d" ,-1822102494,"n=WLe.nEu0{",(void*)6771150153815206631lu,1561301744);
	cmp_vsp("%-110.138d%-%%0143.148u" ,2134772362,2739210354u);
	cmp_vsp("%-154.60i%---171.156X" ,-857650046,907002431u);

	printf("printf(NULL) returns: %i\n", printf(NULL));
	ft_printf("ft_printf(NULL) returns: %i\n", ft_printf(NULL));
}
