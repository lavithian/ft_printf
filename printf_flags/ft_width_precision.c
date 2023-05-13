#include "../ft_printf.h"

int width_handler1 (const char *format) {
  int width = 0;
  // if (flags & FLAG6)
  while (*format == '0' || !ft_isdigit(*format)) {
    format++;
  }
  width = ft_atoi(format);
  return width;
}

int precision_handler1(const char *format) {
  int width = 0;
  // if (flags & FLAG9)
  while (!ft_isdigit(*format) || *format == '0') {
    format++;
  }
  width = ft_atoi(format);
  return width;
}

void width_precision(int flags, const char *format, int *width) {
  if (flags & FLAG6) {
    width[0] = width_handler1(format);
  }
  if (flags & FLAG9) {
    while(*format != '.') {
      format++;
    }
    width[1] = precision_handler1(format);
  }
}

void width_precision_args(int flags, va_list args, int *width) {

  if (flags & FLAG7) {
    width[0] = va_arg(args, int);
  }

  if (flags & FLAG10) {
    width[1] = va_arg(args, int);
  }
}
