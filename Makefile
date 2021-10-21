
CFLAGS = -g -Wall -O0 -std=c99 -g
.PHONY: clean all
all: coordtrans
coordtrans: main.o coordtrans.o
	gcc $(CFLAGS) main.o coordtrans.o -o $@ -lm 
clean:
	$(RM) *.o coordtrans