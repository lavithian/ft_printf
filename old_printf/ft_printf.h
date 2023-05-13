/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:39:31 by mickim            #+#    #+#             */
/*   Updated: 2023/05/12 20:44:34 by mickim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# define MEMCHECK(X) \
  if (!X) \
    return (NULL);
# define FLAG1 0b1 // 1
// #
# define FLAG2 0b10 // 2
// +
# define FLAG3 0b100 // 4
// ' '
# define FLAG4 0b1000 // 8
// -
# define FLAG5 0b10000 // 16
// 0
# define FLAG6 0b100000 // 32
// num1
# define FLAG7 0b1000000 // 64
// first *
# define FLAG8 0b10000000 // 128
// .
# define FLAG9 0b100000000 // 256
// num2 (dependent on precision)
# define FLAG10 0b1000000000 // 512
// second * (dependent on precision)
# define FLAG11 0b10000000000 // 1024

# define FLAG12 0b100000000000 // 2048

// print handlers
int ft_c_handler (int c, int flags, int *width);
int ft_s_handler (char *str, int flags, int *width);
int ft_p_handler(long int p, int flags, int *width);
int ft_d_i_handler(int num, int flags, int *width);
int ft_u_handler(unsigned int u, int flags, int *width);
int ft_hex_handler(unsigned long hex, int flags, int *width, int alcase);
// string maker
int ft_printf(const char *format, ...);
char *ft_print_putchr(char c);
int ft_print_putstr(char *str);
int ft_print_putnbr(int nb);
int ft_putunsignbr(unsigned int nb);
int ft_pointeradd(long p);
char *ft_hex(unsigned long dec, int alcase);
// flags

int ft_flag_manager(int flags, const char *format);
int format_check(char format);
int ft_hex_flag(int alcase);
int ft_plus_flag(int num);
int ft_space_flag(int num);
int ft_negspace_flag(int width, char *string, int len);
int ft_negspace_hex_flag(int width, char *string, int len);
int ft_zero_flag(int width, int len, int num);
int ft_width_flag(int width, int len);
void width_precision(int flags, const char *format, int *width);
void width_precision_args(int flags, va_list args, int *width);
// utilities
int ft_num_sortie (int flags);
int ft_strlen(const char *str);
char *ft_strdup(const char *str);
void *ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_itoa(int n);
int ft_intlen(int n);
char	*ft_unsigned_itoa(unsigned int n);
void	*ft_memset(void *str, int c, size_t len);
int	ft_isdigit(int c);
int ft_isspace(int c);
int	ft_atoi(const char *str);
void	ft_intzero(int *s, size_t n);
#endif
