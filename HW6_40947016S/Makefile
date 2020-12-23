CC:=gcc
objects = hw0601 hw0602 hw0603 hw0604 hw0605
all: $(objects)

$(objects): %: %.c hw5.o
	$(CC) $(CFLAGS) -o $@ $< hw5.o
hw6:
	$(CC) -c hw5.c
clean:
	rm -f *.o
	rm -f $(objects)
