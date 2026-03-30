/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <ckhondji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:52:07 by ckhondji          #+#    #+#             */
/*   Updated: 2025/12/04 19:25:52 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(const char *s, ...);

int	ft_putchar(char c);
int	ft_putstr(const char *str);
int	ft_putnbr(int n);
int	ft_putunbr(unsigned int n);
int	ft_puthex_upper(unsigned int n);
int	ft_puthex_lower(unsigned long long n);
int	ft_putptr(void *ptr);

#endif
