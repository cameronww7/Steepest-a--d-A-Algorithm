outfile: main.o EightGame.o
	g++ -Wall EightGame.o main.o -o outfile

main.o: main.cpp eightGame.h
	g++ -Wall -c main.cpp

EightGame.o: eightGame.h EightGame.cpp
	g++ -Wall -c EightGame.cpp 

clean:
	rm *.o
