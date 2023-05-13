#include "../ft_printf.h"

int ft_d_i_zero(int width, int len, char *string, int flags) {
  int result;

  result = 0;
  result += ft_zero_flag(width, len, flags);
  write(1, string, len);
  free(string);
  return result;
}

int ft_plus_space(int flags, int *width) {
  if(flags & FLAG2) {
    if (flags & FLAG12) {
      write(1, "-", 1);
    } else {
      write(1, "+", 1);
    }
    width[0] += 1;
    return 1;

  } else if (flags & FLAG3) {
    if (flags & FLAG12) {
      write(1, "-", 1);
    } else {
      write(1, " ", 1);
    }
    width[0] += 1;
    return 1;
  }
  return 0;
}

int ft_d_i_handler(int num, int flags, int *width) {
  int result;
  char *string;
  int len;

  result = 0;
  if (num < 0) {
    flags |= FLAG12;
    num = -num;
  }
  string = ft_itoa(num);
  len = ft_set_length(width[1], string, flags);
  if (flags & FLAG5) {
    len += result += ft_plus_space(flags, width);
    // result += ft_d_i_zero(width[0], len, string, flags);
    return result + ft_d_i_zero(width[0], len, string, flags);
  } else if (flags & FLAG4) {
    len += result += ft_plus_space(flags, width);
    return result += ft_neg_controller(string, width[0], len);
  } else if ((flags & FLAG6) || (flags & FLAG7)) {
    result += ft_width_flag(width[0], len);
  }
  len += result += ft_plus_space(flags, width);
  write(1, string, len);
  free(string);
  return result + len;
}
