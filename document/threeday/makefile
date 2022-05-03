target=main
src=$(wildcard ./*.c)
object=$(patsubst %.c,%.o,$(src))
CPPFLAGS=-I./
CC=gcc
$(target):$(object)
	$(CC) -g -o $@ $(object)
%.o:%.c
	$(CC) -g -o $@ -c $< $(CPPFLAGS)

.PHONY:clean
clean:
	-rm -f $(target) $(object)
