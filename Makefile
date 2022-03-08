output: main.o Game.o Util.o
	g++ Game.o main.o Util.o -o out

main.o: main.cpp
	g++ -c main.cpp

Game.o: Game.cpp Game.h
	g++ -c Game.cpp 

Util.o: Util.cpp Util.h
	g++ -c Util.cpp

clean:
	rm *.o out