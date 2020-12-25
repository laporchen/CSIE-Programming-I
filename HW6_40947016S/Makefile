CC:=gcc
objects = hw0601 hw0602 hw0603 hw0604 hw0605
all: $(objects)

$(objects): %: %.c hw6.o
	$(CC) $(CFLAGS) -o $@ $< hw6.o -lm
hw6:
	$(CC) -c hw6.c -lm
clean:
	rm -f *.o
	rm -f $(objects)
