CXX=g++
CXXFLAGS = -Wall -O -g `pkg-config gtkmm-2.4 --cflags --libs`
OBJS = DeckGUI.o mainwindow.o main.o playerhandview.o ScoreBoardView.o
EXEC = other
${EXEC}: $(OBJS)
	   $(CXX) $(OBJS) $(CXXFLAGS) -o $(EXEC)

DeckGUI.o: DeckGUI.h DeckGUI.cc
mainwindow.o: mainwindow.h mainwindow.cc playerhandview.h 
main.o: mainwindow.h main.cc
playerhandview.o: playerhandview.h playerhandview.cc
ScoreBoardView.o: ScoreBoardView.h ScoreBoardView.cpp
clean:
	rm ${EXEC} ${OBJS} ${DEPENDS}
