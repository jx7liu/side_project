a4q4: main.o count.o allcaps.o double.o dropfirst.o echo.o textprocess.o decorator.o 
	g++-5 -std=c++14 main.o count.o allcaps.o double.o dropfirst.o echo.o textprocess.o decorator.o -o a4q4
main.o: main.cc textprocess.h echo.h dropfirst.h double.h decorator.h count.h allcaps.h
	g++-5 -std=c++14 -c main.cc
decorator.o: decorator.cc decorator.h textprocess.h
	g++-5 -std=c++14 -c decorator.cc
echo.o: echo.cc textprocess.h echo.h
	g++-5 -std=c++14 -c echo.cc
count.o: count.cc decorator.h count.h
	g++-5 -std=c++14 -c count.cc
allcaps.o: allcaps.cc allcaps.h decorator.h
	g++-5 -std=c++14 -c allcaps.cc
double.o: double.cc double.h decorator.h
	g++-5 -std=c++14 -c double.cc
dropfirst.o: dropfirst.cc dropfirst.h decorator.h 
	g++-5 -std=c++14 -c dropfirst.cc
textprocess.o: textprocess.cc textprocess.h
	g++-5 -std=c++14 -c textprocess.cc
