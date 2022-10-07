NAME = libftprintf.a
SRCDIR = srcs/
INCLUDESDIR = includes/
CC = gcc
AR = ar rc
SRCS = $(SRCDIR)ft_printf.c $(SRCDIR)ft_putstr.c $(SRCDIR)ft_putnbr.c $(SRCDIR)ft_putptr.c
SRCS_B = 
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

.c.o: 
	$(CC) -Wall -Wextra -Werror -c $< -o $(<:.c=.o) -I $(INCLUDESDIR)

all: 		$(NAME)

$(NAME): 	$(OBJS)
	$(AR) $(NAME) $(OBJS)
	ranlib $(NAME)

bonus: $(OBJS)
	$(AR) $(NAME) $(OBJS)
	ranlib $(NAME)

clean: 
	rm -f $(OBJS)

fclean: 	clean
	rm -f $(NAME)

re:			fclean all
