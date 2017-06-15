CMP = gcc
CFLAGS = -Wall -c
LFLAGS =  -Llib -lSC -lMTBC -g -o
BDIR = "build/SimpleComputer"
all: main

run:
	@./bin/SimpleComputer

main: build/main.o lib/libSC.a lib/libMTBC.a
	@mkdir -p bin
	@echo "\033[32mBuild main: \033[0m"
	$(CMP) build/main.o $(LFLAGS) bin/SimpleComputer
	@echo "\033[35m*************************************"
	@echo "Input /"make run"/ for start program"
	@echo "*************************************\033[0m"


build/main.o: main.c
	@mkdir -p build
	@$(CMP) $(CFLAGS) main.c $(LFLAGS) $@

lib/libSC.a: build/sc.o
	@echo "\033[32mBuild Simple Computer static lib: \033[0m"
	@mkdir -p lib
	ar rc lib/libSC.a build/sc.o
	ranlib lib/libSC.a

lib/libMTBC.a: build/mt.o build/bc.o
	@echo "\033[32mBuild My Term & Big Char static lib: \033[0m"
	@mkdir -p lib
	ar rc lib/libMTBC.a build/mt.o build/bc.o
	ranlib lib/libMTBC.a

build/sc.o: simple_computer/sc.c
	@mkdir -p build
	@$(CMP) $(CFLAGS) simple_computer/sc.c $(LFLAGS) $@

build/mt.o: my_term/mt.c
	@mkdir -p build
	@$(CMP) $(CFLAGS) my_term/mt.c $(LFLAGS) $@

build/bc.o: big_chars/bc.c
	@mkdir -p build
	@$(CMP) $(CFLAGS) big_chars/bc.c $(LFLAGS) $@



clean:
	rm -rf build bin lib