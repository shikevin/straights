CXX=g++
CXXFLAGS = -std=c++0x -MMD -Wall -O -g `pkg-config gtkmm-2.4 --cflags --libs`
OBJS = DeckGUI.o mainwindow.o main.o playerhandview.o ScoreBoardView.o Card.o tableview.o HeaderView.o component.o playerselectiondialog.o TableController.o Deck.o Scoreboard.o GameState.o HumanPlayer.o ComputerPlayer.o Player.o Command.o validate.o bin/linux-gcc/libIrrKlang.so
DEPENDS=$(OBJS:.o=.d)
EXEC = other
${EXEC}: $(OBJS)
	   $(CXX) $(OBJS) $(CXXFLAGS) -o $(EXEC)
-include $(DEPENDS)
clean:
	rm ${EXEC} ${OBJS} ${DEPENDS}
