watopoly: main.o dice.o GoToTims.o NeedlesHall.o OSAP.o coop.o SLC.o TimsLine.o academic.o bankrupt.o board.o building.o display.o goosenesting.o gym.o nonproperty.o paytuition.o player.o residence.o 
	g++-5 -std=c++14 main.o dice.o GoToTims.o NeedlesHall.o OSAP.o coop.o SLC.o TimsLine.o academic.o bankrupt.o board.o building.o display.o goosenesting.o gym.o nonproperty.o paytuition.o player.o residence.o -o watopoly

main.o: main.cc display.h board.h dice.h player.h bankrupt.h
	g++-5 -std=c++14 -c main.cc

dice.o: dice.cc dice.h
	g++-5 -std=c++14 -c dice.cc

GoToTims.o: GoToTims.h GoToTims.cc nonproperty.h display.h player.h
	g++-5 -std=c++14 -c GoToTims.cc

NeedlesHall.o: NeedlesHall.cc NeedlesHall.h nonproperty.h display.h player.h
	g++-5 -std=c++14 -c NeedlesHall.cc

OSAP.o: OSAP.cc OSAP.h display.h player.h nonproperty.h 
	g++-5 -std=c++14 -c OSAP.cc

coop.o: coop.cc coop.h display.h nonproperty.h player.h
	g++-5 -std=c++14 -c coop.cc

SLC.o: SLC.h SLC.cc display.h player.h nonproperty.h
	g++-5 -std=c++14 -c SLC.cc

TimsLine.o: TimsLine.cc TimsLine.h display.h nonproperty.h player.h
	g++-5 -std=c++14 -c TimsLine.cc

academic.o: academic.cc academic.h building.h display.h
	g++-5 -std=c++14 -c academic.cc

bankrupt.o: bankrupt.cc bankrupt.h academic.h player.h display.h
	g++-5 -std=c++14 -c bankrupt.cc

board.o: board.cc board.h display.h player.h bankrupt.h dice.h GoToTims.h NeedlesHall.h OSAP.h coop.h SLC.o TimsLine.h academic.h building.h goosenesting.h gym.h nonproperty.h paytuition.h residence.h square.h
	g++-5 -std=c++14 -c board.cc

building.o: building.h building.cc square.h display.h 
	g++-5 -std=c++14 -c building.cc

display.o: display.cc display.h
	g++-5 -std=c++14 -c display.cc

goosenesting.o: goosenesting.h goosenesting.cc player.h display.h nonproperty.h 
	g++-5 -std=c++14 -c goosenesting.cc

gym.o: gym.h gym.cc building.h display.h
	g++-5 -std=c++14 -c gym.cc

nonproperty.o: nonproperty.h nonproperty.cc display.h square.h
	g++-5 -std=c++14 -c nonproperty.cc

paytuition.o: paytuition.h paytuition.cc display.h player.h
	g++-5 -std=c++14 -c paytuition.cc

player.o: player.h player.cc display.h building.h bankrupt.h residence.h gym.h academic.h
	g++-5 -std=c++14 -c player.cc

residence.o: residence.h residence.cc building.h display.h
	g++-5 -std=c++14 -c residence.cc 
