
Othello: main.o Othello.o Player.o
	g++ main.o -o Othello

main.o: main.cpp
	g++ -c main.cpp

Othello.o: Othello.cpp Othello.hpp
	g++ -c Othello.cpp

Player.o: Player.cpp Player.hpp
	g++ -c Player.cpp

clean:
	rm *.o Othello
