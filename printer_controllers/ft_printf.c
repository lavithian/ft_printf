#include "../ft_printf.h"
#include "../.debug.h"

int ft_printf_main(va_list args, const char format, int flags, int *width)
{
  int result;
  int num;

  result = 0;
  num = 0;
  if (format == 'c') {
    result += ft_c_controller(va_arg(args, int), flags, width);
  } else if (format == 's') {
    result += ft_s_controller (va_arg(args, char *), flags, width);
  } else if (format == 'p') {
    result += ft_p_controller(va_arg(args, long int), flags, width);
  } else if ((format == 'd') || (format == 'i')){
    num = va_arg(args, int);
    result += ft_d_i_controller(num, flags, width);
  } else if (format == 'u') {
    result += ft_u_controller(va_arg(args, unsigned int), flags, width);
  } else if (format == 'x') {
    result += ft_hex_controller(va_arg(args, unsigned long int), flags, width, 32);
  } else if (format == 'X') {
    result += ft_hex_controller(va_arg(args, unsigned long int), flags, width, 0);
  } else if (format == '%') {
    result += ft_print_char('%');
  }
  return result;
}

int flag_init(int flags, const char *format, int *width, va_list args) {
  flags = ft_flag_controller(flags, format);
  if ((flags & FLAG6) || (flags & FLAG9)) {
    width_precision(flags, format, width);
  } else if ((flags & FLAG7) || (flags & FLAG10)) {
    width_precision_args(flags, args, width);
  }
  return flags;
}

int ft_printf(const char *format, ...)
{
  int result;
  int flags;
  int width[2];

  result = 0;
  va_list args;
  va_start(args, format);

  while (*format) {

    ft_initzero(width, 2);
    flags = 0;
    if (*format == '%') {
      format++;
      flags = flag_init(flags, format, width, args);
      while (!format_check(*format)) {
        format++;
      }
      result += ft_printf_main(args, *format, flags, width);
    } else {
      write(1, format, 1);
      result += ft_print_char(*format);
    }
    format++;
  }
  va_end(args);
  return result;
}
