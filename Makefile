NAME		= libftprintf.a
DIRSRCS 	= sources/
SRCS 		=	$(addsuffix .c,	\
				$(addprefix ${DIRSRCS},	\
				ft_printf				\
				flags_utils				\
				handlers				\
				putui					\
				putnbr					\
				putptr					\
				putstr					\
				putul_hex				\
				))
LIBDIR		= libft
LIBNAME		= ft
INCLUDES	= ./includes
RM			= rm -rf
OBJS		= ${SRCS:.c=.o}
CC			= cc
FLAGS		= -Wall -Wextra -Werror

.%.o: %.c
	@${CC} ${FLAGS} -o $@ -c $^ -L${LIBDIR} -l${LIBNAME} -I${INCLUDES}

.${LIBDIR}/libft.a:
	@make -C ${LIBDIR}

all: ${NAME}
	@clear

${NAME}:	${OBJS} ${LIBDIR}/libft.a
	@cp ${LIBDIR}/libft.a ${NAME}
	@ar rcs ${NAME} ${OBJS}

clean:
	@${RM} ${OBJS}

fclean:		clean
	@${RM} ${NAME}

lib_re:
	@make -C ${LIBDIR} re

lib_clean:
	@make -C ${LIBDIR} clean

lib_fclean:
	@make -C ${LIBDIR} fclean

lib_all:
	@make -C ${LIBDIR} all

re: lib_re fclean all

.PHONY: all clean fclean re lib_re lib_all lib_fclean lib_clean lib_re