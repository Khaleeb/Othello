
Othello: main.o Othello.o Player.o
	gcc main.o -o Othello

main.o: main.cpp
	gcc -c main.cpp

Othello.o: Othello.cpp Othello.hpp
	gcc -c Othello.cpp

Player.o: Player.cpp Player.hpp
	gcc -c Player.cpp

clean:
	rm *.o output
