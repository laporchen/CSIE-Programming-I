CC:=gcc
objects = hw0501 hw0502 hw0503 hw0505 hw0504
all: $(objects)

$(objects): %: %.c hw5.o
	$(CC) $(CFLAGS) -o $@ $< hw5.o 
hw4:
	$(cc) -c hw5.c 
clean:
	rm -f *.o
	rm -f $(objects)
