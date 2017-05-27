COMPILER = gcc
CFLAGS = -Wall -c
LFLAGS = -L. -lSC -lTERM -g -o

all: main

main: main.o libSC.a libTERM.a
	$(COMPILER) main.o $(LFLAGS) main
	
main.o: main.c
	$(COMPILER) $(CFLAGS) main.c
	
libSC.a: sc.o
	ar rc libSC.a sc.o
	ranlib libSC.a

sc.o: simple_computer/sc.c
	$(COMPILER) $(CFLAGS) simple_computer/sc.c
	
libTERM.a: mt.o
	ar rc libTERM.a mt.o
	ranlib libTERM.a
	
mt.o: my_term/mt.c
	$(COMPILER) $(CFLAGS) my_term/mt.c
	
clean:
	rm main *.o *.a
