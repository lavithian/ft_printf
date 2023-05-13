#ifndef FT_PRINT_H
# define FT_PRINT_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

#define FLAG1 0b1 // 1
// #
#define FLAG2 0b10 // 2
// +
#define FLAG3 0b100 // 4
// ' '
#define FLAG4 0b1000 // 8
// -
#define FLAG5 0b10000 // 16
// 0
#define FLAG6 0b100000 // 32
// num1
#define FLAG7 0b1000000 // 64
// first *
#define FLAG8 0b10000000 // 128
// .
#define FLAG9 0b100000000 // 256
// num2 (dependent on precision)
#define FLAG10 0b1000000000 // 512
// second * (dependent on precision)
#define FLAG11 0b10000000000 // 1024

#define FLAG12 0b100000000000 // 2048
// negative number

int ft_printf(const char *format, ...);
// print controllers
int ft_c_controller (int c, int flags, int *width);
int ft_s_controller (char *str, int flags, int *width);
int ft_d_i_controller(int num, int flags, int *width);
int ft_u_controller(unsigned int num, int flags, int *width);
int ft_hex_controller(unsigned long hex, int flags, int *width, int alcase);
int ft_p_controller(long int p, int flags, int *width);

// printers
int ft_print_char(char c);
char *ft_hex(unsigned long dec, int alcase);

// flag controllers
int ft_flag_controller(int flags, const char *format);
int format_check(char format);
void width_precision(int flags, const char *format, int *width);
void width_precision_args(int flags, va_list args, int *width);
int ft_neg_controller(char *string, int width, int len);

// flag printers
int ft_width_flag(int width, int len);
int ft_zero_flag(int width, int len, int flags);
int ft_sharp_flag(int alcase);

// utilities
int ft_set_length(int width, char *string, int flags);
void	ft_initzero(int *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *str, int c, size_t len);
int	ft_isdigit(int c);
char	*ft_strdup(const char *str);
int ft_strlen_printf(const char *str);
int	ft_atoi(const char *str);
char	*ft_itoa(int n);
char	*ft_unsigned_itoa(unsigned int n);

#endif
