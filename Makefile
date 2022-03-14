output: main.o Game.o Util.o
	g++ -O0 Game.o main.o Util.o -Wall -o out

main.o: main.cpp
	g++ -O0 -c main.cpp

Game.o: Game.cpp Game.h
	g++ -O0 -c Game.cpp 

Util.o: Util.cpp Util.h
	g++ -O0 -c Util.cpp

clean:
	rm *.o out