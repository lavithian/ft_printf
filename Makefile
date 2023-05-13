NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRCS = $(shell find . -type f -name '*.c' ! -path "./old_printf/*" | grep "ft_*")
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

bonus: all

$(NAME): $(patsubst %.c, %.o, $(SRCS))
	@echo "Compiling Library..."
	ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@$(MAKE) clean -s
	@echo "Library Complete! Have fun!"

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	@rm -rf */*.o
	@rm -rf *.o
	@echo "Output files ousted."

fclean: clean
	@rm -rf $(NAME)
	@rm -f *.gch
	@find . -type f ! -path './.*' ! \( -name 'ft_*' -o -name 'printf.h' -o -name 'Makefile' \) -delete
	@echo "Full clean done."

re: fclean all
