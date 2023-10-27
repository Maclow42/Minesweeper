CC = gcc
CPPFLAGS = -MMD
CFLAGS = -Wall -Wextra -O3
LDFLAGS =
LDLIBS = -lncursesw

SRC = 	main.c \
		./src/mineboard/mineboard.c
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}

all: minesweeper

minesweeper: ${OBJ}
	${CC} ${LDFLAGS} -o $@ $^ ${LDLIBS}

%.o: %.c
	${CC} ${CPPFLAGS} ${CFLAGS} -c -o $@ $<

-include ${DEP}

clean:
	${RM} ${OBJ}
	${RM} ${DEP}
	${RM} minesweeper

run: minesweeper
	./minesweeper
