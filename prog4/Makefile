CXX=g++
CXXFLAGS=-O0 -g -ggdb -Wall -pedantic -std=c++11
LIBS=-lboost_system `ncurses5-config --libs` 
program04:	main.o macierz.o mnozenie_macierzy.o
		$(CXX) -o prog4 main.o macierz.o mnozenie_macierzy.o $(LIBS) $(CXXFLAGS)
main.o:	main.cpp
		$(CXX) -o main.o -c main.cpp $(CXXFLAGS)
macierz.o: macierz.cpp macierz.hpp
		$(CXX) -o macierz.o -c macierz.cpp $(CXXFLAGS)
mnozenie_macierzy.o: mnozenie_macierzy.cpp mnozenie_macierzy.hpp
		$(CXX) -o mnozenie_macierzy.o -c mnozenie_macierzy.cpp $(CXXFLAGS)

clean:
		rm -f *.o
