CC = gcc

SRC = main.c
OBJ = $(SRC:.c=.o)
BIN = main

$(BIN): $(OBJ)

all: $(BIN)

.PHONY: clean

clean:
	${RM} ${BIN} ${OBJ}
