main: main.o re.o nfa.o
	g++ main.o re.o nfa.o -o main

main.o: main.cpp re.h
	g++ -c  main.cpp

re.o: re.cpp re.h new.h todo.h
	g++ -c re.cpp

nfa.o: nfa.cpp nfa.h new.h
	g++ -c nfa.cpp

clean:
	@echo "cleaning project"
	-rm *.o
	@echo "cleaning completed"