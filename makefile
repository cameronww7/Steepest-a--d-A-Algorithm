outfile: main.o EightGame.o GameAi.o State.o StateGenerator.o
	g++ -std=c++11 -Wall EightGame.o main.o GameAi.o State.o StateGenerator.o -o outfile

main.o: main.cpp EightGame.h GameAi.h State.h StateGenerator.h
	g++ -std=c++11 -Wall -c main.cpp

GameAi.o: GameAi.h GameAi.cpp EightGame.h
	g++ -std=c++11 -Wall -c GameAi.cpp

StateGenerator.o: StateGenerator.h StateGenerator.cpp
	g++ -std=c++11 -Wall -c StateGenerator.cpp

State.o: State.h State.cpp
	g++ -std=c++11 -Wall -c State.cpp

EightGame.o: EightGame.h EightGame.cpp
	g++ -std=c++11 -Wall -c EightGame.cpp

clean:
	rm *.o
