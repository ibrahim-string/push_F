# NAME = push_swap.a
# BONUS = checker
# CC = gcc

# CFLAGS = -Wall -Wextra -Werror

# SRC =   main.c \
#         push_swap.c \
#         push_swap_utils.c \
#         push_back.c \
#         movements.c \
#         movements_P2.c \
#         check_arguments.c \
#         regular_cases.c \
#         movements_calculation.c \
#         libft/ft_split.c \
#         libft/ft_atoi.c \
# 	libft/ft_strcmp.c \
# 	libft/ft_strlen.c \
# 	libft/ft_putstring.c \
# 	ft_printf/ft_printf.c \
# 	ft_printf/ft_putchar.c \
# 	ft_printf/ft_putnbr_base.c \
# 	ft_printf/ft_putnbr_base_adr.c \
# 	ft_printf/ft_putnbr_signed.c \
# 	ft_printf/ft_putstr.c \
# 	ft_printf/ft_putnbr_unsigned.c

# SRCB =  bonus/get/get_next_line.c bonus/get/get_next_line_utils.c \
#         bonus/checker.c bonus/check_arg.c bonus/push_swap_utils_bonus.c \
#         bonus/ft_split.c bonus/ft_atoi.c \
#         bonus/movements_bonus_P2.c bonus/movements_bonus.c

# OBJ = $(SRC:.c=.o)

# OBJB = $(SRCB:.c=.o)

# all: $(NAME)

# bonus : $(BONUS)

# $(BONUS): $(OBJB)
# 	$(CC) $(CFLAGS) $(OBJB) -o $(BONUS)

# $(NAME): $(OBJ)
# 	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# clean:
# 	rm -f $(OBJ) $(OBJB)

# fclean: clean
# 	rm -f $(NAME) $(BONUS)

# re: fclean all

# .PHONY: all clean fclean re bonus

NAME = push_swap
BONUS = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC =   main.c \
	push_swap.c \
	push_swap_utils.c \
	push_back.c \
	movements.c \
	movements_P2.c \
	check_arguments.c \
	regular_cases.c \
	movements_calculation.c \
	libft/ft_split.c \
	libft/ft_atoi.c \
	libft/ft_strcmp.c \
	libft/ft_strlen.c \
	libft/ft_putstring.c \
	ft_printf/ft_printf.c \
	ft_printf/ft_putchar.c \
	ft_printf/ft_putnbr_base.c \
	ft_printf/ft_putnbr_base_adr.c \
	ft_printf/ft_putnbr_signed.c \
	ft_printf/ft_putstr.c \
	ft_printf/ft_putnbr_unsigned.c

SRCB = bonus/get/get_next_line.c bonus/get/get_next_line_utils.c \
       bonus/checker.c bonus/check_arg.c bonus/push_swap_utils_bonus.c \
       bonus/ft_split.c bonus/ft_atoi.c \
       bonus/movements_bonus_P2.c bonus/movements_bonus.c

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

all: $(NAME)

bonus : $(BONUS)

$(BONUS): $(OBJB)
	$(CC) $(CFLAGS) $(OBJB) -o $(BONUS)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus