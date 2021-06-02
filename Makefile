DIRLIBFT = libft

LIFBT = ${DIRLIBFT}/libft.a

NAME = push_swap

NAME_BONUS = checker

RM = rm -rf

MAIN = srcs/main.c

MAINBONUS = srcs_bonus/main.c

FILES = save_restart \
	handle_errors \
	load_stacks \
	lists \
	tools \
	operations \
	operations_a \
	operations_b \
	operations_both \
	bubble_sort \
	selection_sort \
	insertion_sort \
	merge_sort \
	array_sorted \
	merge_versions \
	merge_utils \
	algorithm_utils \
	randix_sort \
	move_stacks_utils \
	test_utils \
	divition_sort

SRCS = ${addsuffix .c, ${addprefix srcs/, ${FILES}}}

OBJS =${SRCS:.c=.o}

OBJSMAIN =${MAIN:.c=.o}

OBJSMAINBONUS =${MAINBONUS:.c=.o}

${NAME}: ${LIFBT} ${OBJS} ${OBJSMAIN}
	gcc -o ${NAME} ${OBJSMAIN} ${OBJS} ${LIFBT}

bonus: ${LIFBT} ${OBJS} ${OBJSMAINBONUS}
	gcc -o ${NAME_BONUS} ${OBJSMAINBONUS} ${OBJS} ${LIFBT}

testc: clean test

test:	${LIFBT} ${OBJS}
	gcc -o test test.c ${OBJS} ${LIFBT}

${LIFBT}:
	${MAKE} bonus -C ${DIRLIBFT}

clean:
	${RM} ${OBJS}
	${RM} ${OBJSMAIN}
	${RM} ${OBJSMAINBONUS}

fclean:	clean
	${MAKE} fclean -C ${DIRLIBFT}	
	${RM} ${NAME}
	${RM} ${NAME_BONUS}

