output: main.o Game.o
	g++ Game.o main.o -o output

main.o: main.cpp
	g++ -c main.cpp

Game.o: Game.cpp Game.h
	g++ -c Game.cpp 

clean:
	rm *.o output