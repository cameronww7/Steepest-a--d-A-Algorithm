outfile: main.o EightGame.o
	g++ -std=c++11 -Wall EightGame.o main.o -o outfile

main.o: main.cpp EightGame.h
	g++ -std=c++11 -Wall -c main.cpp

EightGame.o: EightGame.h EightGame.cpp
	g++ -std=c++11 -Wall -c EightGame.cpp 

clean:
	rm *.o
