/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 17:16:47 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/23 10:40:23 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		miniprintf(const char *format, ...);

int		main(void)
{
	int i = 1;

	printf("test solo before\n\n");
	miniprintf("\x1b[4mtest numero : %i\n\x1b[0m", i++);
	miniprintf("mine : test easy int : %d %i %d %i %d %i\n", 2000000, -200000, 20, -20, 0, -0);
	printf("printf : test easy int : %d %i %d %i %d %i\n", 2000000, -200000, 20, -20, 0, -0);


	miniprintf("\x1b[4mtest numero : %i\n\x1b[0m", i++);
	miniprintf("mine : test limit of int : %d %i\nmine : test out of int : %d %i\n", 2147483647, -2147483648, 2147483648, -2147483649);
	printf("printf : test limit of int : %d %i\nprintf : test out of int : %d %i\n", 2147483647, -2147483648, 2147483648, -2147483649);


	miniprintf("\x1b[4mtest numero : %i\n\x1b[0m", i++);
	miniprintf("mine : test easy strings : %s %s %s\n", "wesh alors", "comment va?", "156435");
	printf("printf : test easy strings : %s %s %s\n", "wesh alors", "comment va?", "156435");


	miniprintf("\x1b[4mtest numero : %i\n\x1b[0m", i++);
	miniprintf("mine : test wrong input :%i %d %i\n", "wesh alors", "comment va?", "156435");
	printf("printf : test wrong input :%i %d %i\n", "wesh alors", "comment va?", "156435");


	miniprintf("\x1b[4mtest numero : %i\n\x1b[0m", i++);
	miniprintf("mine : test char :%c %c %c\n", 'c', 'o', 'd');
	printf("printf : test char :%c %c %c\n", 'c', 'o', 'd');

	miniprintf("\x1b[4mtest numero : %i\n\x1b[0m", i++);
	miniprintf("mine : test wrong char :%c %c %c\n", "cod", "cao", "15093684956");
	printf("printf : test wrong char :%c %c %c\n", "cod", "cao", "15093684956");

	miniprintf("\x1b[4mtest numero : %i\n\x1b[0m", i++);
	miniprintf("mine : test color green :%% et ouai poto %%\n", "GREEN", "END");
	miniprintf("mine : test color blue :%% et ouai poto %%\n", "BLUE", "END");
	miniprintf("mine : test color red :%% et ouai poto %%\n", "RED", "END");
	miniprintf("mine : test BOLD RED :%% %% et ouai poto %%\n", "RED", "BOLD", "END");
	miniprintf("mine : test UNDER RED :%% %% et ouai poto %%\n", "RED", "UNDER", "END");

	miniprintf("\x1b[4mtest numero : %i\n\x1b[0m", i++);
	miniprintf("mine : %50s\n", "bonjour");
	printf("prin : %50s\n", "bonjour");
	miniprintf("mine : %050s\n", "bonjour");
	printf("prin : %050s\n", "bonjour");
	miniprintf("mine : %05.1s\n", "bonjour");
	printf("prin : %05.1s\n", "bonjour");

	miniprintf("%i%i\n", -10, 2, "END");
	miniprintf("mine : %%%i%iyataaaaa\n%%", "BLUE", -10, 2, "END");
	miniprintf("mine : %%", "RED");
}
