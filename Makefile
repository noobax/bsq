BIN_NAME = bsq

CC ?= gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = bsq.c bsq2.c

HEADER = bsq.h

OBJS = *.o

all:  fclean bsq.o bsq clean

bsq.o:
	$(CC) -c $(SRCS) $(HEADER) $(CFLAGS)

bsq:
	$(CC) -o $(BIN_NAME) $(OBJS)

clean:
	rm -rf $(OBJS) *.gch

fclean:
	rm -rf $(BIN_NAME)
