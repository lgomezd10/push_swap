DIRLIBFT = libft

LIFBT = ${DIRLIBFT}/libft.a

RM = rm -rf

FILES = handle_errors \
	lists \
	tools \
	operations \
	operations_a \
	operations_b \
	operations_both \
	bubble_sort \
	selection_sort \
	merge_sort \
	array_sorted

SRCS = ${addsuffix .c, ${addprefix srcs/, ${FILES}}}

OBJS =${SRCS:.c=.o}

test:	${LIFBT} ${OBJS}
	gcc -o test test.c ${OBJS} ${LIFBT}

${LIFBT}:
	${MAKE} bonus -C ${DIRLIBFT}

clean:
	${RM} ${OBJS}

fclean:	clean
	${MAKE} fclean -C ${DIRLIBFT}
	${RM} test
