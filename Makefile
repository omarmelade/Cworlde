CC=c++
CFLAGS=-I.
DEPS = Motus.h

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: main.o Motus.o
	$(CC) -o main main.o Motus.o

clean:
	rm -f *.o main