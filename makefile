# $@ : nom de la cible                                                          
# $< : nom de la première dépendance                                            
# $ˆ : liste des dépendances                                                    
# $? : liste des dépendances plus récentes que la cible                         
# $* : nom d’un fichier sans son suffixe  


CC=g++
FLAGS=-std=c++20 -O3 -Isrc -save-temps

.PHONY: clean compile test package all

all: clean compile test package stats

clean: 
	rm -rf building

compile:
	mkdir -p building
	
test: building/range.test.exe\
			building/vector.test.exe

building/range.test.exe: tests/range.test.cpp
	${CC} -o $@ $< ${FLAGS}
	./$@

building/vector.test.exe: tests/vector.test.cpp
	${CC} -o $@ $< ${FLAGS}
	./$@

package:

stats:
	wc -l building/*.s
