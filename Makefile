NAME  = libftprintf.a
CFLAGS= -Wall -Wextra -Werror
CC    = cc
AR    = ar rcs

SRCS  = ft_printf.c ft_utils.c
OBJS  = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
