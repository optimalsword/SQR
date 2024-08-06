CC = gcc
CFLAGS =  -g -Wall -Wextra -fstack-protector -no-pie

.PHONY: clean


compile: clean UAF

clean: 
	rm -f UAF

UAF: 3.9_UAF.c
		$(CC) $(CFLAGS) -o $@ $^