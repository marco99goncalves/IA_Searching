output: main.o Game.o Node.o Tree.o
	g++ Game.o main.o Node.o Tree.o -o out

main.o: main.cpp
	g++ -c main.cpp

Game.o: Game.cpp Game.h
	g++ -c Game.cpp 

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

Tree.o: Tree.cpp Tree.h
	g++ -c Tree.cpp

clean:
	rm *.o out