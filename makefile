hw1: main.o EightGame.o GameAi.o State.o
	g++ -std=c++11 -Wall EightGame.o main.o GameAi.o State.o -o hw1

main.o: main.cpp EightGame.h GameAi.h State.h
	g++ -std=c++11 -Wall -c main.cpp

GameAi.o: GameAi.h GameAi.cpp EightGame.h
	g++ -std=c++11 -Wall -c GameAi.cpp

State.o: State.h State.cpp
	g++ -std=c++11 -Wall -c State.cpp

EightGame.o: EightGame.h EightGame.cpp
	g++ -std=c++11 -Wall -c EightGame.cpp

clean:
	rm *.o
