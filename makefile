outfile: main.o EightGame.o GameAi.o
	g++ -std=c++11 -Wall EightGame.o main.o GameAi.o -o outfile

main.o: main.cpp EightGame.h GameAi.h
	g++ -std=c++11 -Wall -c main.cpp

GameAi.o: GameAi.h GameAi.cpp EightGame.h
	g++ -std=c++11 -Wall -c GameAi.cpp

EightGame.o: EightGame.h EightGame.cpp
	g++ -std=c++11 -Wall -c EightGame.cpp 

clean:
	rm *.o
