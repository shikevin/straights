CXX=g++
CXXFLAGS=-std=c++0x -MMD
OBJECTS=Card.o Command.o ComputerPlayer.o Deck.o HumanPlayer.o Player.o Print.o Scoreboard.o Table.o Input.o main.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=straights
${EXEC}: ${OBJECTS}
		${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS}
clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
