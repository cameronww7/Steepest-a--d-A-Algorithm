outfile: main.o EightGame.o GameAi.o State.o
	g++ -std=c++11 -Wall EightGame.o main.o GameAi.o State.o -o outfile

main.o: main.cpp EightGame.h GameAi.h State.h
	g++ -std=c++11 -Wall -c main.cpp

GameAi.o: GameAi.h GameAi.cpp EightGame.h
	g++ -std=c++11 -Wall -c GameAi.cpp

EightGame.o: EightGame.h EightGame.cpp
	g++ -std=c++11 -Wall -c EightGame.cpp

State.o: State.h State.cpp
	g++ -std=c++11 -Wall -c State.cpp

clean:
	rm *.o
