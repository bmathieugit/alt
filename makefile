CC=g++
FLAGS=-std=c++20 -O3 -Isrc -save-temps

.PHONY: clean compile test package all

all: clean compile test package

clean: 
	rm -rf building

compile:
	mkdir -p building
	
test: building/range.test.exe

building/range.test.exe: tests/range.test.cpp
	${CC} -o $@ tests/range.test.cpp ${FLAGS}
	./$@


