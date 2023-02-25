main: knights.o
	g++ -o main knights.cpp

knights.o: knights.cpp
	g++ -c knights.cpp

clean:
	rm *.o