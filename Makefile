DIRLIBFT = libft

LIFBT = ${DIRLIBFT}/libft.a

NAME = push_swap

RM = rm -rf

FILES = save_restart \
	handle_errors \
	lists \
	tools \
	operations \
	operations_a \
	operations_b \
	operations_both \
	bubble_sort \
	selection_sort \
	merge_sort \
	array_sorted \
	merge_select_sort \
	bubble_sort_2 \
	ger_sort

SRCS = ${addsuffix .c, ${addprefix srcs/, ${FILES}}}

OBJS =${SRCS:.c=.o}

${NAME}: ${LIFBT} ${OBJS}
	gcc -o ${NAME} srcs/main.c ${OBJS} ${LIFBT}

testc: clean test

test:	${LIFBT} ${OBJS}
	gcc -o test test.c ${OBJS} ${LIFBT}

${LIFBT}:
	${MAKE} bonus -C ${DIRLIBFT}

clean:
	${RM} ${OBJS}

fclean:	clean
	${MAKE} fclean -C ${DIRLIBFT}
	${RM} test
	${RM} ${Name}

