CFLAGS = -Wall -Wextra -Werror
CC = gcc
NAME = push_swap.a
AR = ar rcs
SRCS = main.c push_swap.c push_swap_utils.c push_back.c movements.c movements_P2.c check_arguments.c regular_cases.c movements_calculation.c \
		libft/ft_split.c libft/ft_atoi.c libft/ft_strcmp.c libft/ft_strlen.c libft/ft_putstring.c \
		ft_printf/ft_printf.c ft_printf/ft_putchar.c ft_printf/ft_putnbr_base.c ft_printf/ft_putnbr_base_adr.c ft_printf/ft_putnbr_signed.c ft_printf/ft_putstr.c ft_printf/ft_putnbr_unsigned.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $(OBJS)

clean:
	rm -f $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re%