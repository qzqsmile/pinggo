main: main.o re.o nfa.o setcons.o
	g++ -g main.o re.o nfa.o setcons.o -o main
	make clean

main.o: main.cpp re.h
	g++ -c -g  main.cpp

re.o: re.cpp re.h new.h todo.h
	g++ -c -g re.cpp

nfa.o: nfa.cpp nfa.h new.h
	g++ -c -g nfa.cpp

setcons.o: setcons.cpp setcons.h
	g++ -c -g setcons.cpp

clean:
	@echo "cleaning project"
	-rm *.o
	@echo "cleaning completed"