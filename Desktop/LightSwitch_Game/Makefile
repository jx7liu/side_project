a4q3a: main.o cell.o grid.o textdisplay.o
	g++-5 -std=c++14 grid.o cell.o textdisplay.o main.o -o a4q3a
main.o: main.cc textdisplay.h cell.h grid.h 
	g++-5 -std=c++14 -c main.cc
cell.o: cell.h cell.cc observer.h textdisplay.h
	g++-5 -std=c++14 -c cell.cc
grid.o: grid.cc grid.h textdisplay.h cell.h
	g++-5 -std=c++14 -c grid.cc
textdisplay.o: textdisplay.cc textdisplay.h observer.h
	g++-5 -std=c++14 -c textdisplay.cc  


