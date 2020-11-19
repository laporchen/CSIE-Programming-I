CC:=gcc
objects = hw0401 hw0402-1 hw0402-2 hw0403 hw0404 hw0405
all: $(objects)

$(objects): %: %.c hw4.o
	$(CC) $(CFLAGS) -o $@ $< hw4.o
hw4:
	$(cc) -c hw4.c
clean:
	rm -f *.o
	rm -f $(objects)
