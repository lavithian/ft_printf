#include "../ft_printf.h"


int format_check(char format) {
  return (format == 'c' || format == 's' || format == 'p' || format == 'd' || format == 'i' || format == 'u' || format == 'x' || format == 'X');
}

int ft_flag_handler(int flags, const char *format) {
  int i = 0;

  while (!format_check(format[i])) {
    if (format[i] == '#') {
      flags = flags | FLAG1;
      // puts("Raise the Hex 0 flag!");
    }
    if (format[i] == '+') {
      flags = flags | FLAG2;
      // puts("Raise the + or - flag!");
    }
    if (format[i] == ' ') {
      flags = flags | FLAG3;
      // puts("Raise the space flag!");
    }
    if (format[i] == '-') {
      flags = flags | FLAG4;
      // puts("Raise the negative space flag!");
    }
    if ((format[i] == '0') && (ft_isdigit(format[i + 1]))){
      flags = flags | FLAG5;
      // puts("Raise the zero space flag!");
      i++;
    }
    i++;
  }
  return flags;
}

int ft_width_flag_set(int flags, const char *format) {
  int i = 0;
  while (!format_check(format[i])) {
    if (ft_isdigit(format[i]) && format[i] != '0') {
      flags = flags | FLAG6;
      // width[0] = ft_atoi(&format[i]);
      while (ft_isdigit(format[i])) {
        i++;
      }
      // puts("Raise the first width flag");
    } else if (format[i] == '*') {
      flags = flags | FLAG7;
      // width[0] = va_arg(args, int);
      // puts("Raise the first argument flag");
    }
  i++;
  }
  return flags;
}

int ft_precision_flag(int flags, const char *format) {
  int i = 0;

  while (!format_check(format[i])) {
    if (format[i] == '.') {
      flags = flags | FLAG8;
      // puts("Raise the precision flag");
      i++;
      if (ft_isdigit(format[i]) && format[i] != '0') {
        flags = flags | FLAG9;
        // width[1] = ft_atoi(&format[i]);
        while (ft_isdigit(format[i])) {
          i++;
        }
        // puts("Raise the second width flag");
      } else if (format[i] == '*') {
        flags = flags | FLAG10;
        // width[1] = va_arg(args, int);
        // puts("Raise the second argument flag");
      }
    }
    i++;
  }

  return flags;
}

int ft_flag_manager(int flags, const char *format) {
  flags |= ft_flag_handler(flags, format);
  flags |= ft_width_flag_set(flags, format);
  flags |= ft_precision_flag(flags, format);
  return flags;
}
