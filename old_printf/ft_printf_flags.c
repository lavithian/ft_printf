#include "../ft_printf.h"


int ft_hex_flag(int alcase) {
  char x = 'X';
  x += alcase;
  write(1, "0", 1);
  write(1, &x, 1);
  return 2;
}

int ft_plus_flag(int num) {
  if (num > 0) {
    write(1, "+", 1);
  }
  return 1;
}

int ft_space_flag(int num) {
  if (num > 0) {
    write(1, " ", 1);
  }
  return 1;
}

int ft_negspace_flag(int width, char *string, int len) {
  int result;
  result = width = width - len;
  write(1, string, len);
  while(width > 0) {
    write(1, " ", 1);
    width--;
  }
  return result;
}

int ft_negspace_hex_flag(int width, char *string, int len) {
  int result;

  result = width = width - len;
  result += ft_hex_flag(32);
  write(1, string, len);
  while(width - 2 > 0) {
    write(1, " ", 1);
    width--;
  }
  return result;
}

int ft_zero_flag(int width, int len, int num) {
  int result;

  result = width = width - len;
  if (num < 0) {
    write(1, "-", 1);
  }
  while (width > 0) {
    write(1, "0", 1);
    width--;
  }
  return result;
}

int ft_width_flag(int width, int len) {
  int result;
  result = width = width - len;
  while (width > 0) {
    write(1, " ", 1);
    width--;
  }
  return result;
}
