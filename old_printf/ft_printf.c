#include "../ft_printf.h"


int ft_printf_main (va_list args, char format, int flags, int *width) {
  int result = 0;
  int num = 0;

  if (format == 'c') {
    result += ft_c_handler(va_arg(args, int), flags, width);
  } else if (format == 's') {
    result += ft_s_handler (va_arg(args, char *), flags, width);
  } else if (format == 'p') {
    result += ft_p_handler(va_arg(args, long int), flags, width);
  } else if ((format == 'd') || (format == 'i')){
    num = va_arg(args, int);
    result += ft_d_i_handler(num, flags, width);
  } else if (format == 'u') {
    result += ft_u_handler(va_arg(args, unsigned int), flags, width);
  } else if (format == 'x') {
    result += ft_hex_handler(va_arg(args, unsigned long int), flags, width, 32);
  } else if (format == 'X') {
    result += ft_hex_handler(va_arg(args, unsigned long int), flags, width, 0);
  } else if (format == '%') {
    write(1, "%", 1);
    result += 1;
  } else {
    write(1, "Pikapika!\n", 10);
  }
  return result;
}

// initisalise with double pointers

int ft_printf(const char *format, ...) {
  int result = 0;
  int flags = 0;
  int width[2] = {0, 0};

  va_list args;
  va_start(args, format);

  while (*format) {
    if (*format == '%') {
      format++;
      flags = ft_flag_manager(flags, format);
      if ((flags & FLAG6) || (flags & FLAG9)) {
        width_precision(flags, format, width);
      } else if ((flags & FLAG7) || (flags & FLAG10)) {
        width_precision_args(flags, args, width);
      }
      while (!format_check(*format)) {
        format++;
      }
      result += ft_printf_main(args, *format, flags, width);
    } else {
      write(1, format, 1);
      result += 1;
    }
    format++;
    flags = 0;
    ft_intzero(width, 2);
  }
  va_end(args);
  return result;
}
/*
%c Prints a single character.
%s Prints a string (as defined by the common C convention).
%p The void * pointer argument has to be printed in hexadecimal format.
%d Prints a decimal (base 10) number.
%i Prints an integer in base 10.
%u Prints an unsigned decimal (base 10) number.
%x Prints a number in hexadecimal (base 16) lowercase format.
%X Prints a number in hexadecimal (base 16) uppercase format.
%% Prints a percent sign.

Manage any combination of the following flags: ’-0.’ and the field minimum width under all conversions.
Manage all the following flags: ’# +’ (Yes, one of them is a space)
*/
