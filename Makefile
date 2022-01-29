CC=c++
CFLAGS=-I.
DEPS = Wordle.h

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: main.o Wordle.o
	$(CC) -o main main.o Wordle.o

clean:
	rm -f *.o main