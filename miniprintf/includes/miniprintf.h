/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 15:59:27 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/22 15:59:29 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIPRINTF_H
# define MINIPRINTF_H
# include "libft.h"
# include <stdarg.h>

typedef struct				s_s
{
	int						buff;
	int						i;
	int						j;
	int						k;
	int						width;
	int						accu;
	int						zero_fill;

	char					*format;
	char					*tmp;
	char					*output;
	char					*conv;
	char					*str;
	va_list					va;
}							t_ms;

int							miniprintf(const char *format, ...);
int							ft_is_conv(char c, t_ms *s);
void						ft_read_format(t_ms *s);

void						ft_check_width(t_ms *s);
char						*ft_apply_width(t_ms *s, char *str);
void						ft_apply_width_blanc(t_ms *s);
void						ft_apply_width_zero(t_ms *s);

void						ft_check_accu(t_ms *s);
char						*ft_apply_accu(t_ms *s, char *str);

char						*ft_char(t_ms *s);
char						*ft_mod(t_ms *s);
char						*ft_string(t_ms *s);
char						*ft_ptr(t_ms *s);
char						*ft_int(t_ms *s);
char						*ft_fill_conv(t_ms *s);
char						*ft_fill_text(t_ms *s);

void						ft_error_miniprintf(t_ms *s, int error);

void						ft_set_struct_mini(t_ms *s);

#endif
