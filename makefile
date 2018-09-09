# Makefile


all: html.out

html.out: html-driver.o html-parser.o html-scanner.o html.o 
	g++ --std=c++11 -o html.out html-driver.o html-parser.o html-scanner.o html.o

html-driver.o: html-driver.cc html-driver.hh html-parser.hh document.hh comment.hh
	g++ --std=c++11 -c html-driver.cc

html-parser.o: html-parser.cc html-parser.hh html-driver.hh
	g++ --std=c++11 -c html-parser.cc

html-parser.cc html-parser.hh: html-parser.yy
	bison --defines=html-parser.hh -o html-parser.cc html-parser.yy

html-scanner.o: html-scanner.cc html-parser.hh html-driver.hh
	g++ --std=c++11 -c html-scanner.cc

html-scanner.cc: html-scanner.ll
	flex -o html-scanner.cc html-scanner.ll

html.o: html.cc
	g++ --std=c++11 -c html.cc

.PHONY: clean

clean:
	rm *.o html-parser.hh html-parser.cc html-scanner.cc location.hh position.hh stack.hh html.out lex.yy.c

