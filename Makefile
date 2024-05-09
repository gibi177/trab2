all: testa_rainha.cpp   rainha.cpp rainha.hpp rainha.o
	g++ -std=c++11 -Wall rainha.o testa_rainha.cpp -o testa_rainha
	./testa_rainha
	#use comentario se necessario

compile: testa_rainha.cpp   rainha.cpp rainha.hpp rainha.o
	g++ -std=c++11 -Wall rainha.o testa_rainha.cpp -o testa_rainha
	
test: testa_rainha	
	./testa_rainha
	
cpplint: testa_rainha.cpp   rainha.cpp rainha.hpp
	cpplint   --exclude = catch.hpp  *.*
	
gcov: testa_rainha.cpp   rainha.cpp rainha.hpp 
	g++ -std=c++11 -Wall -Wall -fprofile-arcs -ftest-coverage -c rainha.cpp
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage rainha.o testa_rainha.cpp -o testa_rainha
	./testa_rainha
	gcov *.cpp	
	
debug: testa_rainha.cpp   rainha.cpp rainha.hpp 
	g++ -std=c++11 -Wall -Wall -g -c rainha.cpp
	g++ -std=c++11 -Wall  -g rainha.o testa_rainha.cpp -o testa_rainha
	gdb testa_rainha
	
	
cppcheck: testa_rainha.cpp   rainha.cpp rainha.hpp
	cppcheck  --enable=warning . 

valgrind: testa_rainha
	valgrind --leak-check=yes --log-file=valgrind.rpt ./testa_rainha

rainha.o : rainha.cpp rainha.hpp
	g++ -std=c++11 -Wall -Wall -c rainha.cpp
	
testa_rainha: 	testa_rainha.cpp   rainha.cpp rainha.hpp rainha.o
	g++ -std=c++11 -Wall rainha.o testa_rainha.cpp -o testa_rainha

clean:
	rm -rf *.o *.exe *.gc* 
	
	