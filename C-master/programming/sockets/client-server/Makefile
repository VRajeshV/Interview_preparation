SRC=$(shell pwd)/src
INC=$(shell pwd)/inc

all:
	gcc -g -I$(INC) $(SRC)/server.c  $(SRC)/support_funcs.c -o server -lpthread
	gcc -g -I$(INC) $(SRC)/client.c -o client
clean:
	rm $(shell pwd)/server
	rm $(shell pwd)/client
