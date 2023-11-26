SRC=./*.c
INCLUDE=-I./include/
BIN=./main
EXTRA_FLAGS = -Wall -Werror -Wextra -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

all:
	gcc $(SRC) -g -lm $(EXTRA_FLAGS) $(INCLUDE) -o $(BIN)

run:
	$(BIN)

clean:
	rm $(BIN)