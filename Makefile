CMP = gcc
CFLAGS = -Wall -c
LFLAGS =  -Llib -lSC -lMTBC -g -o
BDIR = "build/SimpleComputer"
all: main

main: build/main.o build/mf.o build/rk.o lib/libSC.a lib/libMTBC.a tasm
	@mkdir -p bin
	@echo "\033[32mBuild main: \033[0m"
	$(CMP) build/main.o build/mf.o build/rk.o $(LFLAGS) bin/SimpleComputer
	@echo "\033[35m*************************************"
	@echo "Input /"make run"/ for start program"
	@echo "*************************************\033[0m"

tasm: asm_translator/tasm.c
	@mkdir -p bin
	@$(CMP) asm_translator/tasm.c -Llib -lSC -o bin/tasm


build/main.o: main.c
	@mkdir -p build
	@$(CMP) $(CFLAGS) main.c $(LFLAGS) $@

build/mf.o: main_frame/mf.c
	@mkdir -p build
	@$(CMP) $(CFLAGS) main_frame/mf.c $(LFLAGS) $@

build/rk.o: read_keys/rk.c
	@mkdir -p build
	@$(CMP) $(CFLAGS) read_keys/rk.c $(LFLAGS) $@

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

re: clean main

	
run:
	@./bin/SimpleComputer

clean:
	rm -rf build bin lib
