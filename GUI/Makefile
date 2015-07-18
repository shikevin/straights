CXX=g++
CXXFLAGS = -Wall -O -g `pkg-config gtkmm-2.4 --cflags --libs`
OBJS = deckGUI.o mainwindow.o main.o playerhandview.o ScoreBoardView.o Card.o tableview.o HeaderView.o component.o playerselectiondialog.o TableController.o Deck.o Scoreboard.o GameState.o HumanPlayer.o ComputerPlayer.o Player.o
DEPENDS=$(OBJS:.o=.d)
EXEC = other
${EXEC}: $(OBJS)
	   $(CXX) $(OBJS) $(CXXFLAGS) -o $(EXEC)
-include $(DEPENDS)
clean:
	rm ${EXEC} ${OBJS} ${DEPENDS}
