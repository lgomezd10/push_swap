DIRLIBFT = libft

LIFBT = ${DIRLIBFT}/libft.a

RM = rm -rf

FILES = handle_errors \
	lists \
	operations

SRCS = ${addsuffix .c, ${addprefix srcs/, ${FILES}}}

OBJS =${SRCS:.c=.o}

test:	${LIFBT} ${OBJS}
	gcc -o test test.c ${OBJS} ${LIFBT}

${LIFBT}:
	${MAKE} bonus -C ${DIRLIBFT}

clean:
	${RM} ${OBJS}
