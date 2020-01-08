CC = gcc 
CFLAGS = -Wall -Werror -Wextra -std=c99 -g

SRC = main.c
OBJ = $(SRC:.c=.o)
BIN = main

$(BIN): $(OBJ)

all: $(BIN)

.PHONY: clean

clean:
	${RM} ${OBJ} ${BIN}
