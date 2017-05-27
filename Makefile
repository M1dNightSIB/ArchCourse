COMPILER = gcc
CFLAGS = -Wall -c
LFLAGS = -L. -lSC -g -o

all: main

main: main.o libSC.a
	$(COMPILER) main.o $(LFLAGS) main
	
main.o: main.c
	$(COMPILER) $(CFLAGS) main.c
	
libSC.a: sc.o
	ar rc libSC.a sc.o
	ranlib libSC.a

sc.o: simple_computer/sc.c
	$(COMPILER) $(CFLAGS) simple_computer/sc.c
	
clean:
	rm main *.o libSC.a
